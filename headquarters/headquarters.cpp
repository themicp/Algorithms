#include <cstdio>
#include <list>
#include <vector>

using namespace std;

int N, K, M, i, j, S, T, u, v;
FILE *in = fopen( "headquarters.in", "r" );
vector< list< int > > V( 102 );
list< int >::iterator it;
unsigned long long int W[ 2 ][ 102 ];

int main() {
    fscanf( in, "%i %i %i %i %i", &K, &N, &M, &S, &T );
    --S;
    --T;
    --K;

    for ( i = 0; i < N; ++i ) {
        W[ 0 ][ i ] = W[ 1 ][ i ] = 0;
    }

    for ( i = 0; i < M; ++i ) {
        fscanf( in, "%i %i", &u, &v );
        --u;
        --v;
        V[ u ].push_back( v );
    }

    W[ 0 ][ S ] = 1;
    for ( i = 0; i < K; ++i ) {
        for ( j = 0; j < N; ++j ) {
            for ( it = V[ j ].begin(); it != V[ j ].end(); ++it ) {
                W[ 1 ][ *it ] += W[ 0 ][ j ] % 100000007;
            }
        }
        for ( u = 0 ; u < N; ++u ) {
            W[ 0 ][ u ] = W[ 1 ][ u ];
            W[ 1 ][ u ] = 0;
        }
    }

    printf( "%lld\n", W[ 0 ][ T ] % 100000007 );

    return 0;
}
