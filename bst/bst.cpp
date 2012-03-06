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

void print( Node* A ) {
    int count, i;
    queue< Node* > nodes;
    nodes.push( A );
    count = 1;
    i = count;
    count = 0;

    while ( !nodes.empty() && ( i > 0 || count > 0 ) ) {
        if ( i > 0 ) {
            if ( nodes.front() == NULL ) {
                printf( "NULL " );
            }
            else {
                printf( "( %i, %i ) ", nodes.front()->k, nodes.front()->v );
                nodes.push( nodes.front()->left );
                nodes.push( nodes.front()->right );
                count += 2;
            }
            nodes.pop();
            --i;
        }
        else {
            printf( "\n" );
            i = count;
            count = 0;
        }
    }
    printf( "\n" );
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

Node** successor( Node** A ) {
    if ( ( *A )->left == NULL ) {
        return A;
    }
    return successor( &( *A )->left );
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

void remove( Node** A, int k ) {
    Node** curr = find( A, k );
    if ( *curr == NULL ) {
        return;
    }
    Node temp;
    Node** succ = successor( curr );
    if ( ( *curr )->left == NULL && ( *curr )->right == NULL ) {
        *curr = NULL; //memory leak
        return;
    }
    if ( ( *curr )->left != NULL && ( *curr )->right != NULL ) {
        temp.k = ( **succ ).k;
        temp.v = ( **succ ).v;
        remove( A, ( *succ )->k );
        ( *curr )->k = temp.k;
        ( *curr )->v = temp.v;
        return;
    }
    if ( ( *curr )->left == NULL ) {
        *curr = ( *curr )->right;
        return;
    }
    if ( ( *curr )->right == NULL ) {
        *curr = ( *curr )->left;
        return;
    }
}

Node *A;

int main() {
    insert( &A, 5, 2 );
    insert( &A, 10, 2 );
    insert( &A, 0, 2 );
    insert( &A, 15, 2 );
    insert( &A, -5, 2 );
    insert( &A, 3, 2 );
    insert( &A, 7, 2 );
    print( A );
    printf( "Remove\n" );
    print( A );
    return 0;
}
