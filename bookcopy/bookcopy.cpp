#include <cstdio>
#include <cstdlib>

using namespace std;

void initializeBooks( int *B, int K, int left, int i ) {
    if ( left == 0 ) {
        return;
    }
    else {
        ++B[ i ];
        initializeBooks( B, K, left - 1, i + 1 );
    }
}

void initializeLength( int *B, int K, int *A, int *lens ) {
    int i = 0, j, it = 0;
    while( i < K ) {
        lens[ i ] = 0;
        j = 0;
        while ( j < B[ i ] ) {
            lens[ i ] += A[ it ];
            ++it;
            ++j;
        }
        ++i;
    }
}

int max( int *lens, int K ) {
    int max = 0, i;
    for ( i = 0; i < K; ++i ) {
        if ( lens[ i ] > max ) {
            max = lens[ i ];
        }
    }
    return max;
}

void nextComb( int *B, int K, int *A, int *lens, int i, int &total ) {
    int temp = B[ i ], j, temp_max = 0;
    if ( i + 1 < K ) {
        while ( B[ i ] > 1 ) {
            nextComb( B, K, A, lens, i + 1, total );
            initializeLength( B, K, A, lens );
            temp_max = max( lens, K );
            if ( total == 0 ) {
                total = temp_max;
            }
            else if ( temp_max < total ) {
                total = temp_max;
            }
            --B[ i ];
            ++B[ i + 1 ];
        }
        nextComb( B, K, A, lens, i + 1, total );
        initializeLength( B, K, A, lens );
        temp_max = max( lens, K );
        if ( total == 0 ) {
            total = temp_max;
        }
        else if( temp_max < total ) {
            total = temp_max;
        }
        B[ i ] = temp;
        B[ i + 1 ] = 1;
    }
}

FILE *in = fopen( "bookcopy.in", "r" ), *out = fopen( "bookcopy.out", "w" );
int N, K, *A, each, left, *B, *lens, i, total;

int main() {
    fscanf( in, "%i %i", &N, &K );

    A = ( int* )malloc( N * sizeof( int ) );
    B = ( int* )malloc( K * sizeof( int ) );
    lens = ( int* )malloc( K * sizeof( int ) );

    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i", &A[ i ] );
    }

    B[ 0 ] = N - ( K - 1 );
    for ( i = 1; i < K; ++i ) {
        B[ i ] = 1;
    }

    initializeLength( B, K, A, lens );

    nextComb( B, K, A, lens, 0, total );

    fprintf( out, "%i\n", total );

    return 0;
}
