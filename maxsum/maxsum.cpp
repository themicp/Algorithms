#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

FILE *in = fopen( "maxsum.in", "r" ), *out = fopen( "maxsum.out", "w" );
int N, A, P, i, m;

int main() {
    fscanf( in, "%i", &N );
    
    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i", &A );
        P = max( A + P, A );
        m = max( P, m );
    }

    fprintf( out, "%i\n", m );
    return 0;
}
