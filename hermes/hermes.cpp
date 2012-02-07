#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define NDEBUG

using namespace std;

const int INF = 1987654321;
const int X = 2001;
const int OFFSET = 1000;

int x, y, i, j, N, **A, minx, miny, ax, ay, xprime, yprime, solution = INF, lowx, lowy, highx, highy, oldx, oldy, nextx, nexty, d[ 2 ];

int main() {
    scanf( "%d", &N );
    A = ( int** )malloc( X * sizeof( int* ) ); 
    for ( i = 0; i < X; ++i ) {
        A[ i ] = ( int* )malloc( X * sizeof( int ) );
        fill( A[ i ], A[ i ] + X, INF );
    }

    lowx = lowy = highx = highy = OFFSET;
    oldx = oldy = OFFSET;

    A[ OFFSET ][ OFFSET ] = 0;

    scanf( "%i %i", &ax, &ay );
    ax += OFFSET;
    ay += OFFSET;
    lowx = min( lowx, ax );
    lowy = min( lowy, ay );
    highx = max( highx, ax );
    highy = max( highy, ay );
    for ( i = 0; i < N; ++i ) {
        if ( i != N - 1 ) {
            scanf( "%i %i", &nextx, &nexty );
            nexty += OFFSET;
            nextx += OFFSET;
        }
        miny = minx = INF;
        for ( yprime = lowy; yprime <= highy ; ++yprime ) {
            miny = min( miny, A[ oldx ][ yprime ] + abs( yprime - ay ) );
        }
        for ( xprime = lowx; xprime <= highx; ++xprime ) {
            minx = min( minx, A[ xprime ][ oldy ] + abs( xprime - ax ) );
        }
        lowx = min( lowx, nextx );
        lowy = min( lowy, nexty );
        highx = max( highx, nextx );
        highy = max( highy, nexty );
        d[ 0 ] = abs( oldy - ay );
        d[ 1 ] = abs( oldx - ax );
        for ( j = min( lowy, lowx ); j <= max( highx, highy ); ++j ) {
            A[ j ][ ay ] = A[ j ][ oldy ] + d[ 0 ];
            A[ ax ][ j ] = A[ oldx ][ j ] + d[ 1 ];
        }
        A[ oldx ][ ay ] = miny;
        A[ ax ][ oldy ] = minx;

        oldx = ax;
        oldy = ay;
        ax = nextx;
        ay = nexty;
    }

    for ( i = 0; i < X; ++i ) {
        solution = min( solution, min( A[ ax ][ i ], A[ i ][ ay ] ) );
    }
    printf( "%i\n", solution );

    return 0;
}
