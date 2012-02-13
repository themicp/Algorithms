#include <cstdio>
#include <queue>

using namespace std;

struct Node {
    Node* root;
    int size;
};

Node* find( Node &A ) {
    if ( A.root != NULL ) {
        return find( *A.root );
    }
    return &A;
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

FILE *in = fopen( "mst.in", "r" );
int cntV, cntE, i, u, v, w, D, sum;
priority_queue< pair< int, pair< int, int > > > E;
pair< int, pair< int, int > > top;
Node* V;

int main() {
    fscanf( in, "%i %i", &cntV, &cntE );

    V = ( Node* )malloc( cntV * sizeof( Node ) );

    for ( i = 0; i < cntE; ++i ) {
        fscanf( in, "%i %i %i", &u, &v, &w );
        --u;
        --v;
        V[ u ].size = 1;
        V[ v ].size = 1;
        V[ u ].root = NULL;
        V[ v ].root = NULL;
        E.push( make_pair( -w, make_pair( u, v ) ) );
    }

    while ( D < cntV - 1 && !E.empty() ) {
        top = E.top();
        E.pop();
        if ( find( V[ top.second.first ] ) != find( V[ top.second.second ] ) ) {
            Union( V[ top.second.first ], V[ top.second.second ] );
            sum += -top.first;
            ++D;
        }
    }
    printf( "%i\n", sum );
    return 0;
}
