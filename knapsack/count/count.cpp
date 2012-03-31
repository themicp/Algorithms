#include <cstdio>
#include <algorithm>

using namespace std;

int N, C, c[ 1002 ], i, A[ 1002 ], j;
FILE *in = fopen( "count.in", "r" );

int main() {
    fscanf( in, "%i %i", &C, &N );

    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i", &A[ i ] );
    }
    sort( A, A + N );

    c[ 0 ] = 1;
    for ( i = 1; i <= C; ++i ) {
        j = 0;
        while ( A[ j ] <= i ) {
            c[ i ] += c[ i - A[ j ] ];
            ++j;
        }
    }
    printf( "%i\n", c[ C ] );

    return 0;
}
