#include <cstdio>
#include <cstdlib>

using namespace std;

FILE *in = fopen( "vacation.in", "r" ), *out = fopen( "vacation.out", "w" );

int N, C, *t, i, k, count, temps, days;

int main() {
    fscanf( in, "%i %i", &N, &C );

    t = ( int* )malloc( N * sizeof( int ) );

    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i", &t[ i ] );
    }

    i = 0;
    while ( i < N ) {
        days = 0;
        temps = 0;
        for ( k = i; k < N; ++k ) {
            ++days;
            temps += t[ k ];
            if ( temps/days >= C ) {
                if ( days > count ) {
                    count = days;
                }
            }
        }
        ++i;
    }

    fprintf( out, "%i\n", count );
    return 0;
}
