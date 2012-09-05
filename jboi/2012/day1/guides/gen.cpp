#include <cstdio>

using namespace std;

const int N = 20;
const int M = 11;

int i, j;
FILE *out = fopen( "in", "w" );

int main() {
    fprintf( out, "%i %i\n", N, M );
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < M; ++j ) {
            if ( i < 10 ) {
                fprintf( out, "1" );
            }
            else {
                fprintf( out, "0" );
            }
            if ( j != M - 1 ) {
                fprintf( out, " " );
            }
            else {
                fprintf( out, "\n" );
            }
        }
    }
    return 0;
}
