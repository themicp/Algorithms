#include <cstdio>
#include <string>

using namespace std;

const int UP = 0, LEFT = 2, DIAG = 1;

int LCS( string A, string B, int N, int M ) {
    int W[ N + 1 ][ M + 1 ], i, j, K[ N + 1 ][ M + 1 ];

    for ( j = 0; j <= M; ++j ) {
        W[ 0 ][ j ] = 0;
        K[ 0 ][ j ] = LEFT;
    }

    for ( i = 0; i <= N; ++i ) {
        W[ i ][ 0 ] = 0;
        K[ i ][ 0 ] = UP;
    }

    for ( i = 1; i <= N; ++i ) {
        for ( j = 1; j <= M; ++j ) {
            if ( A[ i - 1 ] == B[ j - 1 ] ) {
                W[ i ][ j ] = W[ i - 1 ][ j - 1 ] + 1;
                K[ i ][ j ] = DIAG;
            }
            else {
                W[ i ][ j ] = max( W[ i - 1 ][ j ], W[ i ][ j - 1 ] );
                if ( W[ i ][ j ] == W[ i - 1 ][ j ] ) {
                    K[ i ][ j ] = UP;
                }
                else {
                    K[ i ][ j ] = LEFT;
                }
            }
        }
    }

    i = N;
    j = M;
    string C = "";
    while ( i >= 0 && j >= 0 ) {
        switch ( K[ i ][ j ] ) {
            case UP:
                --i;
                break;
            case DIAG:
                C = A[ i - 1 ] + C; 
                --i;
                --j;
                break;
            case LEFT:
                --j;
                break;
        }
    }

    printf( "LCS: %s\n", C.c_str() );

    for ( i = 0; i <= N; ++i ) {
        for ( j = 0; j <= M; ++j ) {
            printf( "%i\t", W[ i ][ j ] );
        }
        printf( "\n" );
    }
    for ( i = 0; i <= N; ++i ) {
        for ( j = 0; j <= M; ++j ) {
            switch ( K[ i ][ j ] ) {
                case LEFT:
                    printf( "_" );
                    break;
                case UP:
                    printf( "|" );
                    break;
                case DIAG:
                    printf( "\\" );
                    break;
            }

            printf( "\t" );
        }
        printf( "\n" );
    }

    return W[ N ][ M ];
}

int main() {
    string A = "hello";
    string B = "zero";
    printf( "LCS( %s, %s ) = %i\n", A.c_str(), B.c_str(), LCS( A, B, A.size(), B.size() ) );
    return 0;
}
