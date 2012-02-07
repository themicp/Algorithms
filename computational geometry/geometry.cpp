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

bool Intersect( Point A, Point B, Point C, Point D ) {
    return ( CCW( A, B, C ) * CCW( A, B, D ) < 0 && CCW( C, D, A ) * CCW( C, D, B ) < 0 );
}

bool inTriangle( Point A, Point B, Point C, Point D ) {
    return ( CCW( A, B, D ) * CCW( B, C, D ) > 0 && CCW( B, C, D ) * CCW( C, A, D ) > 0 );
}

void print( Point A ) {
    printf( "{ %.0lf %.0lf %.0lf }\n", A.x, A.y, A.z );
}

FILE *in = fopen( "in", "r" );
Point A, B, C, D;
int method;
double result;

int main() {
    fscanf( in, "%i", &method );
    // 0 - CCW
    // 1 - Intersect
    // 2 - Point in triangle
    fscanf( in, "%lf %lf %lf", &A.x, &A.y, &A.z );
    fscanf( in, "%lf %lf %lf", &B.x, &B.y, &B.z );
    fscanf( in, "%lf %lf %lf", &C.x, &C.y, &C.z );
    if ( method != 0 ) {
        fscanf( in, "%lf %lf %lf", &D.x, &D.y, &D.z );
    }

    if ( method == 0 ) {
        printf( "CCW\n" );
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
    }
    if ( method == 1 ) {
        printf( "Intersection:\n" );
        if ( Intersect( A, B, C, D ) ) {
            printf( "T\n" );
        }
        else {
            printf( "F\n" );
        }
    }
    if ( method == 2 ) {
        printf( "Point in triangle:\n" );
        printf( "%lf\n", CCW( A, B, C ) );
        if ( inTriangle( A, B, C, D ) ) {
            printf( "T\n" );
        }
        else {
            printf( "F\n" );
        }
    }


    return 0;
}
