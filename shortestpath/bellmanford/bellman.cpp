#include <cstdio>

using namespace std;

const int INF = 987654321;

struct Edge {
    int source;
    int destination;
    int weight;
};

FILE *in = fopen( "graph.in", "r" );
int V, E, s, t, i, u, v, j, w, *d, temp;
struct Edge *edges;

int main() {
    fscanf( in, "%i %i %i %i", &V, &E, &s, &t );
    --s;
    --t;
    edges = new struct Edge[ E ];
    d = new int[ V ];

    for ( i = 0; i < E; ++i ) {
        fscanf( in, "%i %i %i", &u, &v, &w );
        --u;
        --v;
        edges[ i ].source = u;
        edges[ i ].destination = v;
        edges[ i ].weight = w;
    }

    for ( i = 0; i < V; ++i ) {
        d[ i ] = i == s ? 0 : INF;
    }

    for ( i = 0; i < V; ++i ) {
        for ( j = 0; j < E; ++j ) {
            u = edges[ j ].source;
            v = edges[ j ].destination;
            w = edges[ j ].weight;
            temp = d[ u ] + w;
            d[ v ] = temp < d[ v ] ? temp : d[ v ];
        }
    }
    printf( "%i\n", d[ t ] );
    return 0;
}
