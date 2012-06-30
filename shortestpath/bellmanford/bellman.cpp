#include <cstdio>
#include <utility>

using namespace std;

const int INF = 987654321;

FILE *in = fopen( "graph.in", "r" );
int V, E, s, t, i, u, v, j, w, *d, temp;
pair< int, pair< int, int > > *edges;

int main() {
    fscanf( in, "%i %i %i %i", &V, &E, &s, &t );
    --s;
    --t;
    edges = new pair< int, pair< int, int > >[ E ];
    d = new int[ V ];

    for ( i = 0; i < E; ++i ) {
        fscanf( in, "%i %i %i", &u, &v, &w );
        --u;
        --v;
        edges[ i ] = make_pair( w, make_pair( u, v ) );
    }

    for ( i = 0; i < V; ++i ) {
        d[ i ] = i == s ? 0 : INF;
    }

    for ( i = 0; i < V; ++i ) {
        for ( j = 0; j < E; ++j ) {
            u = edges[ j ].second.first;
            v = edges[ j ].second.second;
            w = edges[ j ].first;
            temp = d[ u ] + w;
            d[ v ] = temp < d[ v ] ? temp : d[ v ];
        }
    }
    printf( "%i\n", d[ t ] );
    return 0;
}
