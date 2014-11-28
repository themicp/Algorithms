#include <cstdio>
#include <queue>
#include <cstdlib>
#include <stack>

using namespace std;

FILE *in = fopen( "dfs.in", "r" );
int M, N, i, j, u, v, **E, *V, startNode, endNode, pathLength = 0, *minPath;
stack< int > A;

int DFS( int startNode, int endNode ) {
    int i, front;

    if ( startNode == endNode ) {
        return minPath[ endNode ];
    }
    for ( i = 0; i < N; ++i ) {
        if ( E[ startNode ][ i ] ) {
            minPath[ i ] = min( minPath[ i ], minPath[ startNode ] + 1 );
            if ( !V[ i ] ) {
                V[ i ] = 1;
                A.push( i );
            }
        }
    }
    if ( A.size() ) {
        front = A.top();
        A.pop();
        ++pathLength;
        return DFS( front, endNode );
    }
    else {
        return -1;
    }
}

void printEdges() {
    printf( "# " );
    for ( i = 0; i < N; ++i ) {
        printf( "%i ", i );
    }
    printf( "\n" );
    for ( i = 0; i < N; ++i ) {
        printf( "%i ", i );
        for ( j = 0; j < N; ++j ) {
            printf( "%i ", E[ i ][ j ] );
        }
        printf( "\n" );
    }
}

int main() {
    fscanf( in, "%i %i", &M, &N );
    fscanf( in, "%i %i", &startNode, &endNode );

    E = ( int** )malloc( N * sizeof( int* ) );
    V = ( int* )malloc( N * sizeof( int ) );
    minPath = ( int* )malloc( N * sizeof( int ) );
    for ( i = 0; i < N; ++i ) {
        E[ i ] = ( int* )malloc( N * sizeof( int ) );
        V[ i ] = 0;
        minPath[ i ] = M + 1;

        for ( j = 0; j < N; ++j ) {
            E[ i ][ j ] = 0;
        }
    }

    for ( i = 0; i < M; ++i ) {
        fscanf( in, "%i %i", &u, &v );
        E[ u ][ v ] = 1;
        E[ v ][ u ] = 1;
    }

    V[ startNode ] = 1;
    minPath[ startNode ] = 0;
    printf( "Path length: %i\n", DFS( startNode, endNode ) );
    return 0;
}
