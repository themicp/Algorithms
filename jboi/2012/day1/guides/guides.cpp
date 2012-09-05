#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

FILE *in = fopen( "in", "r" ), *out = fopen( "out", "w" );
bool forbid[ 105 ];
map< pair< long long int, int >, int > W;
int N, M, i, j, x, A[ 20 ][ 105 ], T[ 20 ];
int debug;

int bruteforce( bool forbid[ 105 ], int m, int depth, long long int forbit ) {
    ++debug;
    int i, j, current, mincost = 987654321;
    long long int temp = forbit;
    for ( i = 0; i < N; ++i ) {
        if ( forbid[ i ] ) {
            continue;
        }
        forbid[ i ] = true;
        forbit |= 1 << i;
        current = A[ m ][ i ];
        if ( m < M - 1 ) {
            if ( W[ make_pair( forbit, m + 1 ) ] == 0 ) { 
                current += bruteforce( forbid, m + 1, depth + 1, forbit );
            }
            else {
                current += W[ make_pair( forbit, m + 1 ) ];
            }
        }
        mincost = min( current, mincost );
        forbid[ i ] = false;
        forbit = temp;
    }
    W[ make_pair( forbit, m ) ] = mincost;
    return mincost;
}

int main() {
    fscanf( in, "%i %i", &N, &M );
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < M; ++j ) {
            fscanf( in, "%i", &x );
            T[ j ] += x;
            A[ j ][ i ] = x;
        }
    }
    for ( i = 0; i < M; ++i ) {
        printf( "--%i--", i );
        for ( j = 0; j < N; ++j ) {
            A[ i ][ j ] = T[ i ] - A[ i ][ j ];
            printf( "%i ", A[ i ][ j ] );
        }
        printf( "\n" );
    }
    printf( "%i\n", bruteforce( forbid, 0, 0, 0 ) );
    printf( "Calls: %i\n", debug );
    return 0;
}
