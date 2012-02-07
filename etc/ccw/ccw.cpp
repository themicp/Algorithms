#include <cstdio>

using namespace std;

struct Point {
    double x;
    double y;
    double z;
};

double CCW( Point A, Point B, Point C ) {
    return ( B.x - A.x ) * ( C.y - A.y ) - ( B.y - A.y ) * ( C.x - A.x );
}

void print( Point A ) {
    printf( "{ %.0lf %.0lf %.0lf }\n", A.x, A.y, A.z );
}

FILE *in = fopen( "ccw.in", "r" );
double result;
Point A, B, C;

int main() {
    fscanf( in, "%lf %lf %lf", &A.x, &A.y, &A.z );
    fscanf( in, "%lf %lf %lf", &B.x, &B.y, &B.z );
    fscanf( in, "%lf %lf %lf", &C.x, &C.y, &C.z );

    result = CCW( A, B, C );
    if ( result < 0 ) {
        printf( "Right\n" );
    }
    else if ( result > 0 ) {
        printf( "Left\n" );
    }
    else {
        printf( "Same line\n" );
    }
    return 0;
}
