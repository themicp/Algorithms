#include <cstdio>
#include <vector>

using namespace std;

struct point {
    float x;
    float y;
};

struct segment {
    point start;
    point end;
};

inline bool inRange( float start, float end, float value ) {
    if ( end < start ) {
        float t = end;
        end = start;
        start = t;
    }

    return start < value && value < end;
}

inline bool inSegment( point p, segment s ) {
    return inRange( s.start.x, s.end.x, p.x ) && inRange( s.start.y, s.end.y, p.y );
}

float getY( float a, float b, int x ) {
    return a*x + b;
}

int main() {
    bool flag;

    int p, q, i, x[ 2 ], y[ 2 ], ver[ 2 ];
    struct point A, B, C, D, M;
    struct segment AB, CD;

    float a[ 2 ], b[ 2 ];

    ver[ 0 ] = 0;
    ver[ 1 ] = 0;

    printf( "Enter the cordinates of A: " );
    scanf( "%f %f", &A.x, &A.y );
    printf( "\nEnter the cordinates of B: " );
    scanf( "%f %f", &B.x, &B.y );
    printf( "\nEnter the cordinates of C: " );
    scanf( "%f %f", &C.x, &C.y );
    printf( "\nEnter the cordinates of D: " );
    scanf( "%f %f", &D.x, &D.y );

    AB.start = A;
    AB.end = B;

    CD.start = C;
    CD.end = D;

    if ( B.x - A.x == 0 ) { //initialize AB
        x[ 0 ] = A.x;
        ver[ 0 ] = 1;
    }
    else {
        a[ 0 ] = ( B.y - A.y )/(float)( B.x - A.x );    
        b[ 0 ] = -a[ 0 ]*A.x + A.y;
        printf( "\nAB:\ny = %.3f*x + %.3f\n\n", a[ 0 ], b[ 0 ] );
    }

    if ( D.x - C.x == 0 ) { //initialize CD
        x[ 1 ] = C.x;
        ver[ 1 ] = 1;
    }
    else {
        a[ 1 ] = ( D.y - C.y )/(float)( D.x - C.x );    
        b[ 1 ] = -a[ 1 ]*C.x + C.y;
        printf( "\nCD:\ny = %.3f*x + %.3f\n\n", a[ 1 ], b[ 1 ] );
    }

    if ( a[ 0 ] == a[ 1 ] ) {
        printf( "F\n" );
        return 0;
    }
    if ( ver[ 0 ] == 1 ) {
        if ( ver[ 1 ] == 1 ) {
            if ( A.x != C.x ) {
                printf( "F\n" );
                return 0;
            }
            printf( "T\n" );
            return 0;
        }
        if ( inRange( AB.start.y, AB.end.y, getY( a[ 1 ], b[ 1 ], A.x ) ) ) {
            printf( "T\n" );
            return 0;
        }
        printf( "F\n" );
        return 0;
    }
    if ( ver[ 1 ] == 1 ) {
        if ( inRange( CD.start.y, CD.end.y, getY( a[ 0 ], b[ 0 ], C.x ) ) ) {
            printf( "T\n" );
            return 0;
        }
        printf( "F\n" );
        return 0;
    }
    M.x = ( b[ 1 ] - b[ 0 ] )/( a[ 0 ] - a[ 1 ] );
    M.y = a[ 0 ] * M.x + b[ 0 ];
    printf( "\nM( %f, %f )\n", M.x, M.y  );
    if ( inSegment( M, AB ) && inSegment( M, CD ) ) {
        printf( "T\n" );
        return 0;
    }
    printf( "F\n" );

    return 0;
}
