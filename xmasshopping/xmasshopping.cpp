#include <cstdio>
#include <cstdlib>

using namespace std;

struct Coords {
    int x;
    int y;
};

void BF( char *combs, int N, int key ) {
    if ( combs[ key ] == 0 + '0' ) {
        combs[ key ] = 1 + '0';
    }
    else {
        combs[ key ] = 0 + '0';
        if ( key > 0 ) {
            BF( combs, N, key - 1 );
        }
    }
}

bool complete( char *combs, int N ) {
    int i;
    for ( i = 0; i < N; ++i ) {
        if ( combs[ i ] == 0 + '0' ) {
            return false;
        }
    }
    return true;
}

int d( int x, int y, int dx, int dy ) {
    return abs( x - dx ) + abs( y - dy );
}

int totalTime( char* combs, int N, Coords *coordinates, Coords *start ) {
    int i, key, total = 0;
    Coords people[ 2 ];
    people[ 0 ] = start[ 0 ];
    people[ 1 ] = start[ 1 ];

    for ( i = 0; i < N; ++i ) {
        if ( combs[ i ] == 0 + '0' ) {
            key = 0;
        }
        else {
            key = 1;
        }
        total += d( people[ key ].x, people[ key ].y, coordinates[ i ].x, coordinates[ i ].y );
        people[ key ].x = coordinates[ i ].x;
        people[ key ].y = coordinates[ i ].y;
    }

    return total;
}

char *combs;
int i, N, R, C, min, current;
Coords *coordinates;
Coords start[ 2 ];
FILE *in = fopen( "xmasshopping.in", "r" ), *out = fopen( "xmasshopping.out", "w" );

int main() {
    fscanf( in, "%i %i %i", &N, &R, &C );

    combs = (char*)malloc( N * sizeof( char ) );
    coordinates = ( Coords* )malloc( N * sizeof( Coords ) );

    fscanf( in, "%i %i %i %i", &start[ 0 ].x, &start[ 0 ].y, &start[ 1 ].x, &start[ 1 ].y );

    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i %i", &coordinates[ i ].x, &coordinates[ i ].y );
        combs[ i ] = 0 + '0';
    }

    i = 0;
    min = totalTime( combs, N, coordinates, start );
    while ( !complete( combs, N ) ) {
        current = totalTime( combs, N, coordinates, start );
        if ( current < min ) {
            min = current;
        }
        BF( combs, N, N - 1 );
    }

    current = totalTime( combs, N, coordinates, start );
    if ( current < min ) {
        min = current;
        printf( "%s\n", combs );
    }

    fprintf( out, "%i\n", min );

    return 0;
}
