#include <cstdio>
#include <map>
#include <string>

using namespace std;

FILE *in = fopen( "tongues.in", "r" ), *out = fopen( "tongues.out", "w" );
string c = "ynficwlbkuomxsevzpdrjgthaq", a = "abcdefghijklmnopqrstuvwxyz", text;
char buffer[ 110 ];
int T, i, N, j, pos;

int main() {
    fscanf( in, "%i", &T );
    fgets( buffer, 110, in );
    for ( i = 0; i < T; ++i ) {
        fgets( buffer, 110, in );
        text = buffer;
        for ( j = 0; j < (int)text.size(); ++j ) {
            if ( text[ j ] != ' ' ) {
                pos = c.find( text[ j ] );
                text[ j ] = a[ pos ];
            }
        }
        fprintf( out, "Case #%i: %s\n", i + 1, text.c_str() );
    }
    return 0;
}
