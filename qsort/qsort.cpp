#include <cstdio>
#include <cstdlib>

using namespace std;

void QuickSort ( int *a, int start, int end ) {
    int piv = a[ start ];
    int o;
    int i;
    int key = start + 1;
    int num;
    int gt = start;
    int lt = start;
    int temp;

    if ( start != end ) {
        for ( i = start + 1; i < end; ++i ) {
            if ( a[ i ] >= piv ) {
                temp = a[ key ];
                a[ key ] = a[ i ];
                for ( o = key; o < i; ++o ) {
                    num = a[ o + 1 ];
                    a[ o + 1 ] = temp;
                    temp = num;
                }
                ++gt;
            }
            else {
                temp = a[ start ];
                a[ start ] = a[ i ];
                for ( o = start; o < i; ++o ) {
                    num = a[ o + 1 ];
                    a[ o + 1 ] = temp;
                    temp = num;
                }
                ++key;
                ++lt;
            }
        }
        if ( lt > start ) {
            QuickSort( a, start, lt );
        }
        if ( gt > start ) {
            QuickSort( a, key, end );
        }
    }
}

int main() {
    FILE *in = fopen( "qsort.in", "r" );
    FILE *out = fopen( "qsort.out", "w" );

    int n;
    int *a, i;

    fscanf( in, "%i", &n );

    a = ( int* )malloc( n * sizeof( int ) );

    for ( i = 0; i < n; ++i ) {
        fscanf( in, "%d", &a[ i ] );
    }

    QuickSort( a, 0, 15 );

    for ( int i = 0; i < n; ++i ) {
        fprintf( out, "%i\n", a[ i ] );
    }

    return 0;
}
