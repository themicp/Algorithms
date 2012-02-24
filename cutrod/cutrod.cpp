#include <cstdio>
#include <algorithm>

using namespace std;

FILE *in = fopen( "cutrod.in", "r" );
int N, *P, i, j, k, temp, maxi, *w;

int main() {
    fscanf( in, "%i", &N );
    P = (int*)malloc( ( N + 1 )*sizeof( int ) );
    for ( i = 1; i <= N; ++i ) {
        fscanf( in, "%i", &P[ i ] );
    }

    w = (int*)malloc( N * sizeof( int ) );

    i = 1;
    while( i <= N ) {
        j = 1;
        k = i - 1;
        maxi = 0;
        while ( j <= k ) {
            temp = w[ j ] + w[ k ];
            maxi = max( temp, maxi );
            ++j;
            --k;
        }
        w[ i ] = max( maxi, P[ i ] );
        ++i;
    }
    printf( "%i\n", w[ N ] );

    return 0;
}
