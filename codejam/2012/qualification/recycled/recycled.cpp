#include <cstdio>
#include <string>

using namespace std;

int T, i, j, x, y, temp, S, prevx;
FILE *in = fopen( "recycled.in", "r" ), *out = fopen( "recycled.out", "w" );
string prev = "";

string toString( int N ) {
    string a;
    char b[ 2 ];

    while ( N > 0 ) {
        b[ 0 ] = ( N % 10 ) + '0';
        a.insert( 0, b );
        N /= 10;
    }
    return a;
}

void recycle( int x, int y, int n ) {
    char b[ 2 ];
    string a = "";
    int temp = x, ntemp = n;

    while ( ntemp > 0 ) {
        b[ 0 ] = ( temp % 10 ) + '0';
        a.insert( 0, b );
        temp /= 10;
        --ntemp;
    }
    a.append( toString( temp ) );
    if ( a <= toString( y ) && a > toString( x ) && a[ 0 ] != '0' ) {
        if ( a != prev || prevx != x ) {
            ++S;
        }
        prev = a;
        prevx = x;
    }
    if ( n < (int)a.size() - 1 ) {
        recycle( x, y, n + 1 );
    }
}

int main() {
    fscanf( in, "%i", &T );
    for ( i = 0; i < T; ++i ) {
        fscanf( in, "%i %i", &x, &y );
        temp = x;
        if ( y < 10 ) {
            fprintf( out, "Case #%i: 0\n", i + 1 );
            continue;
        }
        while ( temp < y ) {
            recycle( temp, y, 1 );
            ++temp;
        }
        fprintf( out, "Case #%i: %i\n", i + 1, S );
        S = 0;
    }
    return 0;
}
