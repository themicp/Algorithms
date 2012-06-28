#include <cstdio>
#include <queue>
#include <list>

using namespace std;

const int N = 1000;
const int INF = 987654321;

FILE *in = fopen( "maxflow.in", "r" );
int i, j, n, s, t, u, u1, w, v;
bool *marked, done = false;
int *P;
int E[ N ][ N ], flow[ N ][ N ];
list< pair< int, int > >::iterator it;
pair< int, int > edge;
queue< int > q;

bool bfs() {
    for ( i = 0; i < v; ++i ) {
        marked[ i ] = 0;
    }
    q.push( s );
    marked[ s ] = 1;
    while ( !q.empty() && !done ) {
        u = q.front();
        q.pop();
        for ( i = 0; i < v; ++i ) {
            if ( E[ u ][ i ] - flow[ u ][ i ] > 0 && !marked[ i ] ) {
                q.push( i );
                marked[ i ] = 1;
                P[ i ] = u;
            }
        }
    }
    return marked[ t ];
}

int maxFlow() {
    int i, j, increment, max_flow = 0;
    for ( i = 0; i < v; ++i ) {
        for ( j = 0; j < v; ++j ) {
            flow[ i ][ j ] = 0;
        }
    }
    while ( bfs() ) {
        increment = INF;
        for ( i = t; P[ i ] > -1; i = P[ i ] ) {
            increment = min( increment, E[ P[ i ] ][ i ] - flow[ P[ i ] ][ i ] );
        }
        for ( i = t; P[ i ] > -1; i = P[ i ] ) {
            flow[ P[ i ] ][ i ] += increment;
            flow[ i ][ P[ i ] ] -= increment;
        }
        max_flow += increment;
    }
    return max_flow;
}

int main() {
    fscanf( in, "%i %i", &v, &n );
    t = v - 1;
    s = 0;
    marked = new bool[ v ];
    P = new int[ v ];
    for ( i = 0; i < v; ++i ) {
        P[ i ] = -1;
        for ( j = 0; j < v; ++j ) {
            E[ i ][ j ] = -1;
        }
    }
    for ( i = 0; i < n; ++i ) {
        fscanf( in, "%i %i %i", &u, &u1, &w );
        E[ u ][ u1 ] = w;
    }
    printf( "%i\n", maxFlow() );

    return 0;
}
