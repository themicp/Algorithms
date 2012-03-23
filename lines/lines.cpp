#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

char *word;
int N, C, i, j, left, w, *L, *nline;
FILE *in = fopen( "lines.in", "r" );

int main() {
    fscanf( in, "%i %i", &N, &C );

    word = new char[ C + 1 ];
    nline = new int[ N + 1 ];
    L = new int[ N + 1 ];

    L[ 0 ] = 0;
    for ( i = 1; i <= N; ++i ) {
        nline[ i ] = C * C * N; //initialization
        fscanf( in, "%s\n", word );
        L[ i ] = strlen( word );
        j = i;
        left = C - L[ j ];
        while ( left >= 0 && j > 0 ) {
            w = left * left;
            w += nline[ j - 1 ];
            nline[ i ] = min( nline[ i ], w );
            --j;
            left -= L[ j ] + 1;
        }
    }

    printf( "%i\n", nline[ N ] );

    delete[] word;
    delete[] nline;
    delete[] L;
    fclose( in );
    return 0;
}
