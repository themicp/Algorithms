#include <cstdio>
#include <string>
#include <map>
#include <utility>

#define max( a, b ) a > b? a: b

using namespace std;

map< pair< string, string >, int > memoize;
map< pair< string, string >, int >::iterator find;

int lcs( string a, string b ) {
    int i, N = a.length(), M = b.length();
    int substring_lcs[ M + 1 ][ N + 1 ];

    for ( int m = M; m >= 0; --m ) {
        for ( int n = N; n >= 0; --n ) {
            if ( m == M || n == N ) {
                substring_lcs[ m ][ n ] = 0;
            }
            else if ( a.substr( n )[ 0 ] == b.substr( m )[ 0 ] ) {
                substring_lcs[ m ][ n ] = substring_lcs[ m + 1 ][ n + 1 ] + 1;
            }
            else {
                substring_lcs[ m ][ n ] = max ( substring_lcs[ m + 1 ][ n ], substring_lcs[ m ][ n + 1 ] );
            }
        }
    }

    return substring_lcs[ 0 ][ 0 ];
}

int main() {
    FILE* fi = fopen( "lcs.in", "r" );
    FILE* fo = fopen( "lcs.out", "w" );
    int i, o;

    string a ( "ARRABBAQAPPQPXGHJKFHKJSH" );
    string b ( "APPABNBAAMMQQPXIWUOYEWHDA" );
    printf( "%i\n", lcs( a, b ) ); 


    fclose( fi );
    fclose( fo );
    return 0;
}

