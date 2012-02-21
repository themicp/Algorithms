#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

FILE *in = fopen( "knapsack.in", "r" );

int N, C, i, j, w;
int *W, *A;

int main() {
    fscanf( in, "%i %i", &N, &C );

    A = (int*)malloc( N * sizeof( int ) );
    W = (int*)malloc( C * sizeof( int ) );

    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i", &A[ i ] );
    }

    while ( j <= C ) {
        w = -1;
        for ( i = 0; i < N; ++i ) {
            if ( j - A[ i ] >= 0 ) {
                w = ( w == -1 )? W[ j - A[ i ] ]: min( w, W[ j - A[ i ] ] );
            }
        }
        W[ j ] = w + 1; 
        ++j;
    }
    printf( "%i\n", W[ C ] );
    return 0;
}
