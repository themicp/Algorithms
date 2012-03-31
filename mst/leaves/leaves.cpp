#include <cstdio>
#include <queue>

using namespace std;

struct Node {
    Node* root;
    int size;
};

int N, M, L, u, v, w, i, j, sum;
priority_queue< pair< int, pair< int, int > > > E;
pair< int, int > top;
bool marked[ 1002 ], P[ 1002 ], flag;
FILE *in = fopen( "leaves.in", "r" );
Node *V;

Node* find( Node &A ) {
    if ( A.root != &A ) {
        A.root = find( *A.root );
    }
    return A.root;
}

void Union( Node &A, Node &B ) {
    Node *xroot, *yroot;
    int xsize, ysize;
    xroot = find( A ), yroot = find( B );
    xsize = ( *xroot ).size, ysize = ( *yroot ).size;

    if ( xsize > ysize ) {
        ( *yroot ).root = xroot;
        ( *xroot ).size += ysize;
        return;
    }
    ( *xroot ).root = yroot;
    ( *yroot ).size += xsize;
    return;
}

int main() {
    fscanf( in, "%i %i %i", &N, &M, &L );

    V = new Node[ N ];

    for ( i = 0; i < M; ++i ) {
        fscanf( in, "%i %i %i", &u, &v, &w );
        --u;
        --v;
        V[ u ].size = V[ v ].size = 1;
        V[ u ].root = &V[ u ];
        V[ v ].root = &V[ v ];
        E.push( make_pair( -w, make_pair( u, v ) ) );
    }

    for ( i = 0; i < L; ++i ) {
        fscanf( in, "%i", &u );
        P[ u - 1 ] = 1;
    }

    while ( !E.empty() ) {
        w = E.top().first;
        top = E.top().second;
        E.pop();
        flag = 1;
        if ( P[ top.first ] ) {
            if ( P[ top.second ] ) {
                if ( !marked[ top.first ] && !marked[ top.second ] ) {
                    if ( N == 2 ) {
                        sum += -w;
                    }
                    flag = 0;
                }
            }
            if ( marked[ top.first ] ) {
                flag = 0;
            }
        }
        else if ( P[ top.second ] ) {
            if ( marked[ top.second ] ) {
                flag = 0;
            }
        }

        if ( flag ) {
            if ( find( V[ top.first ] ) != find( V[ top.second ] ) ) {
                Union( V[ top.first ], V[ top.second ] );
                marked[ top.first ] = 1;
                marked[ top.second ] = 1;
                sum += -w;
            }
        }
    }
    printf( "%i\n", sum );
    return 0;
}
