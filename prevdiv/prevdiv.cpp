#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long int lli;

lli gcd( lli a, lli b ) {
    if ( b > a ) {
        return gcd( b, a );
    }
    if ( b == 0 ) {
        return a;
    }
    return gcd( b, a % b );
}

lli lcm( lli a, lli b ) {
    return ( a * b ) / gcd( a, b );
}

FILE *in = fopen( "prevdiv.in", "r" ), *out = fopen( "prevdiv.out", "w" );
int N, a, i, result;
lli b = 1;

int main() {
    fscanf( in, "%i", &N );
    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i", &a );
        b = lcm( a, b );
        if ( b != 0 && ( lli )a % b == 0 ) {
            result = max( result, a );
        }
    }

    printf( "%i\n", result );
    return 0;
}
