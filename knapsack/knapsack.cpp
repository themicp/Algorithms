#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

FILE *in = fopen( "knapsack.in", "r" );

const int INF = 123456789;

int N, C, i, j, w;
int *W, *A;

int main() {
    fscanf( in, "%i %i", &N, &C );

    A = (int*)malloc( N * sizeof( int ) );
    W = (int*)malloc( C * sizeof( int ) );

    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i", &A[ i ] );
        W[ A[ i ] ] = 1;
    }

    for ( j = 0; j <= C; ++j ) {
        W[ j ] = INF;
        for ( i = 0; i < N; ++i ) {
            if ( j - A[ i ] >= 0 ) {
                W[ j ] = min( w, W[ j - A[ i ] ] + 1 );
            }
        }
    }
    printf( "%i\n", W[ C ] );
    return 0;
}
