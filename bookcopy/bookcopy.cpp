#include <cstdio>
#include <cstdlib>

using namespace std;

bool validResult( int *A, int K, int N, int value ) {
    int current = 0, i = 0, j = 0;

    while ( j < K ) {
        current = 0;

        while ( current + A[ i ] <= value && i < N - ( K - ( j + 1 ) ) ) {
            current += A[ i ];

            ++i;
        }

        if ( A[ i ] > value && i < N ) {
            return false;
        }

        ++j;
    }

    if ( i < N ) {
        return false;
    }

    return true;
}

int binarySearch( int *A, int K, int N, int a, int low, int high ) {
    int mid = ( low + high )/2;

    if ( low == high ) {
        return low + 1;
    }

    if ( validResult( A, K, N, mid + 1 ) ) {
        binarySearch( A, K, N,  a, low, mid );
    }
    else {
        binarySearch( A, K, N,  a, mid + 1, high );
    }
}

FILE *in = fopen( "bookcopy.in", "r" ), *out = fopen( "bookcopy.out", "w" );
int N, K, *A, i, total, maxValue;

int main() {
    fscanf( in, "%i %i", &N, &K );

    A = ( int* )malloc( N * sizeof( int ) );

    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i", &A[ i ] );
        maxValue += A[ i ];
    }

    fprintf( out, "%i\n", binarySearch( A, K, N, maxValue, 0, maxValue - 1 ) );

    return 0;
}
