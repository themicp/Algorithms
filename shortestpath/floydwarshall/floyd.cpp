#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000;
const int INF = 987654321;

FILE *in = fopen( "floyd.in", "r" );
int i, j, E, u, v, w, k, V;
int path[ N ][ N ];

void print( int path[ N ][ N ], int n ) {
    for ( i = 0; i < n; ++i ) {
        for ( j = 0; j < n; ++j ) {
            printf( "%i\t", path[ i ][ j ] );
        }
        printf( "\n" );
    }
}

int main() {
    fscanf( in, "%i", &E );
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            path[ i ][ j ] = i != j ? INF : 0;
        }
    }
    for ( i = 0; i < E; ++i ) {
        fscanf( in, "%i %i %i", &u, &v, &w );
        V = max( u, V );
        V = max( v, V );
        --u;
        --v;
        path[ u ][ v ] = w;
        path[ v ][ u ] = w;
    }

    for ( k = 0; k < V; ++k ) {
        for ( i = 0; i < V; ++i ) {
            for ( j = 0; j < V; ++j ) {
                path[ i ][ j ] = min( path[ i ][ j ], path[ i ][ k ] + path[ k ][ j ] );
            }
        }
    }
    print( path, V );

    return 0;
}
