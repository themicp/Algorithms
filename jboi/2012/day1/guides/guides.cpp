#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

FILE *in = fopen( "in", "r" ), *out = fopen( "out", "w" );
bool forbid[ 105 ];
map< string, int > W;
int N, M, i;
string forbchar;

void bruteforce( bool forbid[ 105 ], int m, int depth, string forbchar ) {
    int i, j;
    string temp = forbchar;
    for ( i = 0; i < N; ++i ) {
        if ( forbid[ i ] ) {
            continue;
        }
        forbid[ i ] = true;
        forbchar += i + '0';
        if ( m < M - 1 ) {
            bruteforce( forbid, m + 1, depth + 1, forbchar );
        }
        forbid[ i ] = false;
        forbchar = temp;
    }
}

int main() {
    fscanf( in, "%i %i", &N, &M );
    forbchar = "";
    bruteforce( forbid, 0, 0, forbchar );
    return 0;
}
