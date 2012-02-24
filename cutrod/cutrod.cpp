#include <cstdio>
#include <algorithm>

using namespace std;

FILE *in = fopen( "cutrod.in", "r" );
int N, *P, i, j, temp, maxi, *w;

int main() {
    fscanf( in, "%i", &N );
    P = ( int* )malloc( ( N + 1 ) * sizeof( int ) );
    for ( i = 1; i <= N; ++i ) {
        fscanf( in, "%i", &P[ i ] );
    }

    w = ( int* )malloc( N * sizeof( int ) );

    for ( i = 1; i <= N; ++i ) {
        maxi = 0;
        for ( j = 1; j <= i - j; ++j ) {
            temp = w[ j ] + w[ i - j ];
            maxi = max( temp, maxi );
        }
        w[ i ] = max( maxi, P[ i ] );
    }
    printf( "%i\n", w[ N ] );

    return 0;
}
