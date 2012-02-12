#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Neighbor {
    int key;
    int w;
};

FILE *in = fopen( "prim.in", "r" );
int i, j, cntV, cntE, u, v, w, sum, neighbor[ 2005 ];
Neighbor V[ 2005 ][ 2005 ];
bool marked[ 2005 ];
vector< pair< int, pair< int, int > > > E( 1 );
priority_queue< pair< int, int > > front;
pair< int, int > top;

int main() {
    fscanf( in, "%i %i", &cntV, &cntE );

    E.resize( cntE );

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

    while ( neighbor[ j ] == 0 ) {
        ++j;
    }
    marked[ j ] = true;
    for ( i = 0; i < neighbor[ j ]; ++i ) {
        front.push( make_pair( -V[ j ][ i ].w, V[ j ][ i ].key ) );
    }

    while ( !front.empty() ) {
        top = front.top();
        front.pop();
        if ( !marked[ top.second ] ) {
            marked[ top.second ] = true;
            sum += -top.first;
            for ( i = 0; i < neighbor[ top.second ]; ++i ) {
                if ( !marked[ V[ top.second ][ i ].key ] ) {
                    front.push( make_pair( -V[ top.second ][ i ].w, V[ top.second ][ i ].key ) );
                }
            }
        }
    }
    printf( "%i\n", sum );

    return 0;
}
