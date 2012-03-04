#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Neighbor {
    int key;
    int w;
};

FILE *in = fopen( "path.in", "r" );
int i, j, cntV, cntE, u, v, w, sum, neighbor[ 2005 ], d[ 2005 ], S, T;
Neighbor V[ 2005 ][ 2005 ];
bool marked[ 2005 ];
vector< pair< int, pair< int, int > > > E( 1 );
priority_queue< pair< int, int > > frontier;
pair< int, int > top;

int main() {
    fscanf( in, "%i %i %i %i", &cntV, &cntE, &S, &T );
    --S;
    --T;

    E.resize( cntE );

    for ( i = 0; i < cntV; ++i ) {
        d[ i ] = 987654321;
    }
    for ( i = 0; i < cntE; ++i ) {
        fscanf( in, "%i %i %i", &u, &v, &w );
        --u;
        --v;
        V[ u ][ neighbor[ u ] ].key = v;
        V[ v ][ neighbor[ v ] ].key = u;
        V[ u ][ neighbor[ u ] ].w = w;
        V[ v ][ neighbor[ v ] ].w = w;
        ++neighbor[ u ];
        ++neighbor[ v ];
    }

    d[ 0 ] = 0;
    marked[ 0 ] = true;
    for ( i = 0; i < neighbor[ S ]; ++i ) {
        frontier.push( make_pair( -V[ S ][ i ].w, V[ S ][ i ].key ) );
        d[ V[ S ][ i ].key ] = V[ S ][ i ].w;
    }

    while ( !frontier.empty() ) {
        top = frontier.top();
        frontier.pop();
        if ( !marked[ top.second ] ) {
            marked[ top.second ] = true;
            for ( i = 0; i < neighbor[ top.second ]; ++i ) {
                if ( !marked[ V[ top.second ][ i ].key ] ) {
                    d[ V[ top.second ][ i ].key ] = min( d[ V[ top.second ][ i ].key ], -top.first + V[ top.second ][ i ].w );
                    frontier.push( make_pair( -( V[ top.second ][ i ].w + -top.first ), V[ top.second ][ i ].key ) );
                }
            }
        }
    }
    printf( "%i\n", d[ T ] );

    return 0;
}
