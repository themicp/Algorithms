#include <cstdio>
#include <vector>
#include <list>
#include <queue>

using namespace std;

FILE *in = fopen( "motivations.in", "r" );
int i, dummy, N, *n, *mark, u, j, c[ 2 ], counter, **E;
bool error;

void BFS( int i ) {
    int j;
    queue< int > q;
    int front;

    mark[ i ] = 0;
    ++c[ 0 ];
    q.push( i );
    while ( !q.empty() ) {
        front = q.front();
        for ( j = 0; j < n[ front ]; ++j ) {
            if ( mark[ E[ front ][ j ] ] == -1 ) {
                ++c[ !mark[ front ] ];
                q.push( E[ front ][ j ] );
            }
            if ( mark[ front ] == mark[ E[ front ][ j ] ] ) {
                error = 1;
                return;
            }
            mark[ E[ front ][ j ] ] = !mark[ front ];
        }
        q.pop();
    }
}

int main() {
    fscanf( in, "%i", &N );

    E = new int*[ N ];
    n = new int[ N ];
    mark = new int[ N ];

    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i %i", &dummy, &n[ i ] ); 
        E[ i ] = new int[ n[ i ] ];

        for ( j = 0; j < n[ i ]; ++j ) {
            fscanf( in, "%i", &u );
            --u;
            E[ i ][ j ] = u;
        }
        mark[ i ] = -1;
    }

    for ( i = 0; i < N; ++i ) { 
        if ( error ) {
            break;
        }
        if ( mark[ i ] == -1 ) {
            BFS( i );
        }
    }

    if ( error ) {
        printf( "0\n0\n" );
    }
    else {
        for ( j = 0; j < 2; ++j ) {
            printf( "%i ", c[ j ] );
            counter = 0;
            for ( i = 0; i < N; ++i ) {
                if ( mark[ i ] == j ) {
                    printf( "%i", i + 1 );
                    ++counter;
                    if ( counter != c[ j ] ) {
                        printf( " " );
                    }
                }
            }
            printf( "\n" );
        }
    }

    return 0;
}
