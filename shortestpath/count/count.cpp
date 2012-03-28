#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

FILE *in = fopen( "../path.in", "r" );
int i, cntV, cntE, u, v, neighbor[ 2005 ], d, S, T, counter;
int V[ 2005 ][ 2005 ];
bool marked[ 2005 ];
vector< pair< int, pair< int, int > > > E( 1 );
queue< pair< int, int > > frontier;
pair< int, int > top;

int main() {
    fscanf( in, "%i %i %i %i", &cntV, &cntE, &S, &T );
    --S;
    --T;

    E.resize( cntE );

    for ( i = 0; i < cntE; ++i ) {
        fscanf( in, "%i %i %*i", &u, &v );
        --u;
        --v;
        V[ u ][ neighbor[ u ] ] = v;
        V[ v ][ neighbor[ v ] ] = u;
        ++neighbor[ u ];
        ++neighbor[ v ];
    }

    marked[ S ] = 1; 
    for ( i = 0; i < neighbor[ S ]; ++i ) {
        frontier.push( make_pair( 1, V[ S ][ i ] ) );
    }

    d = INF;
    while ( !frontier.empty() ) {
        top = frontier.front();
        frontier.pop();
        if ( top.second == T ) {
            if ( d == top.first ) {
                ++counter;
            }
            else {
                counter = d < top.first ? counter : 1;
            }
            d = min( d, top.first );
        }
        for ( i = 0; i < neighbor[ top.second ]; ++i ) {
            u = V[ top.second ][ i ];
            if ( !marked[ u ] ) {
                frontier.push( make_pair( top.first + 1, u ) );
            }
        }
        marked[ top.second ] = 1;
    }
    printf( "Possible shortest paths: %i\n", counter );
    printf( "Shortest path: %i\n", d );

    return 0;
}
