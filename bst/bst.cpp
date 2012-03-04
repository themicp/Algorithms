#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

struct Node {
    int k;
    int v;
    Node* right;
    Node* left;
};

void insert( Node** A, int k, int v ) {
    Node* b = ( Node* )malloc( sizeof( Node ) );
    Node** result;
    b->k = k;
    b->v = v;

    if ( *A == NULL ) {
        *A = b;
        return;
    }

    result = search( A, k );

    if ( k == ( *result )->k ) {
        *result = b;
        return;
    }
    if ( k < ( *result )->k ) {
        ( *result )->left = b;  
        return;
    }
    ( *result )->right = b;
}

Node** search( Node** A, int k ) {
    Node* root = *A;

    if ( k < root->k ) {
        return root->left == NULL ? A : search( &root->left, k );
    }
    if ( k > root->k ) {
        return root->right == NULL ? A : search( &root->right, k );
    }
    return A;
}

Node** successor( Node** A ) {
    if ( ( *A )->left == NULL ) {
        return A;
    }
    return successor( &( *A )->left );
}

void remove( Node** A, int k ) {
    Node** succ = successor( A );
    if ( ( *A )->left == NULL && ( *A )->right == NULL ) {
        *A = NULL; //memory leak
        return;
    }
    if ( ( *A )->left != NULL && ( *A )->right != NULL ) {
        *A = succ;
        remove( A, ( *succ )->k );
        return;
    }
    if ( ( *A )->left == NULL ) {
        *A = ( *A )->right;
        return;
    }
    if ( ( *A )->right == NULL ) {
        *A = ( *A )->left;
        return;
    }
}

Node** find( Node** A, int k ) {
    if ( *A == NULL ) {
        return A;
    }
    if ( k > ( *A )->k ) {
        return find( &( *A )->right, k );
    }
    if ( k < ( *A )->k ) {
        return find( &( *A )->left, k );
    }
    return A;
}

void print( Node* A ) {
    queue< Node > nodes;
    nodes.push_back( A );

    while ( !nodes.empty() ) {
        if ( nodes.front() == NULL ) {
            printf( "NULL " );
        }
        printf( "( %i, %i ) ", nodes.front()->k, nodes.front()->v );
        nodes.push( nodes.front()->left );
        nodes.push( nodes.front()->right );
        nodes.pop();
    }
}

Node *A;

int main() {
    return 0;
}
