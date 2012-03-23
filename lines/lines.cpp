#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

struct Newline {
    double w;
    int left;
};

double w;
char **word;
Newline *nline;
int N, C, i, j, k, left, sum;
FILE *in = fopen( "lines.in", "r" );

int main() {
    fscanf( in, "%i %i", &N, &C );

    word = new char*[ N ];
    nline = new Newline[ N ];

    for ( i = 0; i < N; ++i ) {
        word[ i ] = new char[ C + 1 ];
        nline[ i ].w = pow( ( double )C, 2 ) * N;
        fscanf( in, "%s\n", word[ i ] );
    }

    for ( i = 0; i < N; ++i ) {
        j = i;
        left = C - strlen( word[ j ] );
        while ( left >= 0 && j >= 0 ) {
            w = pow( ( double )left, 2 );
            w += ( j > 0 ) ? nline[ j - 1 ].w : 0;
            nline[ i ].w = min( nline[ i ].w, w );

            sum = 0;
            --j;
            if ( j >= 0 ) {
                for ( k = j; k <= i; ++k ) {
                    sum += strlen( word[ k ] );
                    sum += ( k != i ) ? 1 : 0;
                }
                left = C - sum; 
            }
        }
    }

    printf( "%.0lf\n", nline[ N - 1 ].w );

    delete[] word;
    delete[] nline;
    fclose( in );
    return 0;
}
