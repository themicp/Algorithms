#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void BruteForce( int *array, int len ) {
    --len;
    if ( array[ len ] == 0 ) {
        array[ len ] = 1;
    }
    else if ( array[ len ] == 1 && len > 0 ) {
        array[ len ] = 0;
        BruteForce( array, len );
    }
}

FILE *in = fopen( "lcs.in", "r" ), *out = fopen( "lcs.out", "w" );
char a[ 11 ], b[ 11 ], tempa[ 11 ], tempb[ 11 ];
int i, o, len[ 2 ], *rma, *rmb, max;
bool done, subbf;

int main() {
    fscanf( in, "%s\n", a );
    fscanf( in, "%s\n", b );

    strcpy( tempa, a );
    strcpy( tempb, b );

    len[ 0 ] = strlen( a );
    len[ 1 ] = strlen( b );

    rma = ( int* )calloc( len[ 0 ], sizeof( int ) );
    rmb = ( int* )calloc( len[ 1 ], sizeof( int ) );

    while ( !done ) {
        strcpy( tempa, a );
        done = true;
        for ( i = len[ 0 ] - 1; i >= 0; --i ) {
            if ( rma[ i ] == 1 ) {
                for ( o = i; o < len[ 0 ] - 1; ++o ) {
                    tempa[ o ] = tempa[ o + 1 ];
                }
                tempa[ o ] = '\0';

            }
            if ( rma[ i ] != 1 ) {
                done = false;
            }
        }
        subbf = false;
        while ( !subbf ) {
            strcpy( tempb, b );
            subbf = true;
            for ( i = len[ 1 ] - 1; i >= 0; --i ) {
                if ( rmb[ i ] == 1 ) {
                    tempb[ i ] = '0';
                    for ( o = i; o < len[ 1 ] - 1; ++o ) {
                        tempb[ o ] = tempb[ o + 1 ];
                    }
                    tempb[ o ] = '\0';

                }
                if ( rmb[ i ] != 1 ) {
                    subbf = false;
                }
            }
            if ( strcmp( tempa, tempb ) == 0 ) {
                if ( strlen( tempa ) > max ) {
                    max = strlen( tempa );
                }
            }
            if ( !subbf ) {
                BruteForce( rmb, len[ 1 ] );
            }
        }
        for ( i = 0; i < len[ 1 ]; ++i ) {
            rmb[ i ] = 0;
        }
        if ( !done ) {
            BruteForce( rma, len[ 0 ] );
        }
    }

    fprintf( out, "%i\n", max );

    fclose( in );
    fclose( out );
    return 0;
}
