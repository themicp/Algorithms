#include <cstdio>
#include <cstdlib>

using namespace std;

FILE *in = fopen( "in", "r" );
int i, N, *h, prev, next, S;

int main() {
    fscanf( in, "%i", &N );
    h = new int[ N ];
    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i", &h[ i ] );
    }

    for ( i = 1; i < N - 1; ++i ) {
        prev = h[ i - 1 ];
        next = h[ i + 1 ];
        if ( prev > h[ i ] ) {
            if ( next > prev || ( next < prev && next > h[ i ] ) ) {
                ++S;
            }
        }
        else if ( prev < h[ i ] ) {
            if ( next < prev || ( next > prev && next < h[ i ] ) ) {
                ++S;
            }
        }
    }

    printf( "%i\n", S );

    free( h );
    return 0;
}
