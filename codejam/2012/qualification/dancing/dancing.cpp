#include <cstdio>

using namespace std;

int T, N, p, t[ 3 ], i, S, minp, score, j, total;
FILE *in = fopen( "dancing.in", "r" ), *out = fopen( "dancing.out", "w" );

int main() {
    fscanf( in, "%i", &T );
    for ( i = 0; i < T; ++i ) {
        fscanf( in, "%i %i %i", &N, &S, &p ); 
        minp = p;
        if ( p > 2 ) {
            minp += 2 * ( p - 2 );
        }
        for ( j = 0; j < N; ++j ) {
            fscanf( in, "%i", &score );
            if ( score >= minp ) {
                if ( p < 2 ) {
                    ++total;
                    continue;
                }
                if ( score - minp <= 1 && S > 0 ) {
                    --S;
                    ++total;
                }
                if ( score - minp > 1 ) {
                    ++total;
                }
            }
        }
        fprintf( out, "Case #%i: %i\n", i + 1, total );
        total = 0;
    }
    return 0;
}
