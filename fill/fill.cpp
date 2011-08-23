#include <cstdio>

using namespace std;

void fill( int a[ 100 ][ 100 ], int x, int y, int * counter, int n ) {
    if ( y < 0 || x < 0 || y >= n || x >= n || a[ x ][ y ] == 0 ) {
        return;
    }
    ++*counter;
    a[ x ][ y ] = 0;
    fill( a, x, y - 1, counter, n );
    fill( a, x + 1, y, counter, n );
    fill( a, x, y + 1, counter, n );
    fill( a, x + 1, y, counter, n );
}
int main() {
    FILE * in = fopen( "fill.in", "r" );
    int n, i, o = 0;
    fscanf( in, "%i", &n );
    int a[ 100 ][ 100 ];
    int x, y;
    int counter = 0;
    int * ptrCounter = &counter;
    fscanf( in, "%i", &x );
    fscanf( in, "%i", &y );
    while ( o <= n ) {
        for ( i = 0; i < n; ++i ) {
            fscanf( in, "%i", &a[ o ][ i ] );
        }
        ++o;
    }
    fill( a, x, y, ptrCounter, n );
    for ( o = 0; o < n; ++o ) {
        for ( i = 0; i < n; ++i ) {
            printf( "%i ", a[ o ][ i ] ); 
        }
        printf( "\n" );
    }
    printf( "changed: %i\n", counter );
    return 0;
}
