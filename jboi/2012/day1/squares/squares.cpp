#include <cstdio>
#include <algorithm>

using namespace std;

FILE *in = fopen( "in", "r" ), *out = fopen( "out", "w" );
int N, x, y, l, i, line[ 10000005 ], width, height, row[ 10000005 ], counter, side;

int main() {
    fscanf( in, "%i", &N );
    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i %i %i", &x, &y, &l );
        ++line[ y ];
        ++row[ x ];
        width = max( width, line[ y ] );
        height = max( height, row[ x ] );
    }
    counter = N;
    side = 2;
    while ( side <= min( height, width ) ) {
        counter += ( width - side + 1 ) * ( height - side + 1 );
        ++side;
    }
    fprintf( out, "%i\n", counter );
    return 0;
}
