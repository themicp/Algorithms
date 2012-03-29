#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

FILE *in = fopen( "../path.in", "r" );
int i, cntV, cntE, u, v, neighbor[ 2005 ], *d, S, T, counter, top;
int V[ 2005 ][ 2005 ];
bool done;
queue< int > frontier;

int main() {
    fscanf( in, "%i %i %i %i", &cntV, &cntE, &S, &T );
    --S;
    --T;

    d = new int[ cntV ];
    for ( i = 0; i < cntV; ++i ) {
        d[ i ] = INF;
    }

    for ( i = 0; i < cntE; ++i ) {
        fscanf( in, "%i %i", &u, &v );
        --u;
        --v;
        V[ u ][ neighbor[ u ] ] = v;
        V[ v ][ neighbor[ v ] ] = u;
        ++neighbor[ u ];
        ++neighbor[ v ];
    }

    d[ S ] = 0; 
    for ( i = 0; i < neighbor[ S ]; ++i ) {
        frontier.push( V[ S ][ i ] );
        d[ V[ S ][ i ] ] = 1;
        if ( V[ S ][ i ] == T ) {
            counter = 1;
            done = true;
            break;
        }
    }

    while ( !frontier.empty() && !done ) {
        top = frontier.front();
        frontier.pop();
        for ( i = 0; i < neighbor[ top ]; ++i ) {
            u = V[ top ][ i ];
            if ( d[ top ] + 1 <= d[ u ] ) {
                if ( u != T ) {
                    frontier.push( u );
                }
                else {
                    counter = d[ top ] + 1 < d[ u ] ? 1 : counter + 1;
                }
            }
            d[ u ] = min( d[ top ] + 1, d[ u ] );
        }
    }
    printf( "Possible shortest paths: %i\n", counter );
    printf( "Shortest path: %i\n", d[ T ] );

    delete[] d;
    return 0;
}
