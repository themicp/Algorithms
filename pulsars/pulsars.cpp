#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    long long int x;
    long long int y;
    int key;
    double distance;
};

Point *Q;
int mink;

long long int CCW( Point A, Point B, Point C ) {
    return ( B.x - A.x ) * ( C.y - A.y ) - ( B.y - A.y ) * ( C.x - A.x );
}

void Swap( Point *A, int i, int j ) {
    Point temp;
    temp = A[ i ];
    A[ i ] = A[ j ];
    A[ j ] = temp;
}

int cmp( const void * a, const void * b ) {
    Point A = *( Point* )a;
    Point B = *( Point* )b;
    if ( CCW( Q[ 0 ], A, B ) > 0 ) {
        return -1;
    }
    if ( CCW( Q[ 0 ], A, B ) == 0 ) {
        return A.distance - B.distance;
    }
    return 1;
}

bool samePoint( Point A, Point B ) {
    if ( A.x == B.x && A.y == B.y ) {
        return true;
    }
    return false;
}

FILE *in = fopen( "pulsars.in", "r" ), *out = fopen( "pulsars.out", "w" );
int N, i, *S, j, ccw;
priority_queue< int > seq;

int main() {
    fscanf( in, "%d", &N );

    Q = ( Point* )malloc( N * sizeof( Point ) );
    S = ( int* )malloc( N * sizeof( int ) );

    mink = 0;
    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%lld %lld", &Q[ i ].x, &Q[ i ].y );
        Q[ i ].key = i;
        if ( Q[ i ].y < Q[ mink ].y ) {
            mink = i;
        }
        if ( Q[ i ].y == Q[ mink ].y ) {
            if ( Q[ i ].x < Q[ mink ].x ) {
                mink = i;
            }
        }
    }

    for ( i = 0; i < N; ++i ) {
        if ( mink != i ) {
            Q[ i ].distance = sqrt( 
                pow( (double)( Q[ i ].x - Q[ mink ].x ), 2 ) +
                pow( (double)( Q[ i ].y - Q[ mink ].y ), 2 )
            );
        }
    }
    Q[ mink ].distance = -1;
    Swap( Q, mink, 0 );
    qsort( Q + 1, N - 1, sizeof( Point ), cmp );

    S[ 0 ] = 0;
    j = 1;
    i = 1;
    // Graham
    while ( i < N ) {
        if ( j < 2 ) {
            if ( !samePoint( Q[ S[ j - 1 ] ], Q[ i ] ) ) {
                S[ j ] = i;
                ++j;
            }
            ++i;
            continue;
        }
        ccw = CCW( Q[ S[ j - 2 ] ], Q[ S[ j - 1 ] ], Q[ i ] );
        if ( ccw > 0 ) {
            S[ j ] = i;
            ++j;
            ++i;
        }
        else {
            if ( !samePoint( Q[ S[ j - 1 ] ], Q[ i ] ) ) {
                --j;
            }
            else {
                if ( Q[ S[ j - 1 ] ].key > Q[ i ].key ) {
                    S[ j - 1 ] = i;
                }
                ++i;
            }
        }
    }

    //Output
    for ( i = 0; i < j; ++i ) {
        seq.push( -( Q[ S[ i ] ].key + 1 ) );
    }
    fprintf( out, "%i\n", (int)seq.size() );
    while ( !seq.empty() ) {
        fprintf( out, "%i\n", -seq.top() );
        seq.pop();
    }

    free( Q );
    free( S );
    
    return 0;
}

