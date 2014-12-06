#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

#define N 26
struct Node {
    char value;
    Node* children[ N ];
    bool finish;
};

Node* initNode( char value, bool finish ) {
    Node* node = ( Node * )malloc( sizeof( Node ) );

    node->value = value;
    node->finish = finish;
    for ( int j = 0; j < N; ++j ) {
        node->children[ j ] = NULL;
    }

    return node;
}

void insertWord( Node* root, string word ) {
    int i, ascii;
    Node* currentNode = root;
    Node* newNode;

    for ( i = 0; i < word.length(); ++i ) {
        ascii = (int)( toupper( word[ i ] ) - 'A' );

        if ( currentNode->children[ ascii ] == NULL ) {
            newNode = initNode( toupper( word[ i ] ), false );
            currentNode->children[ ascii ] = newNode;
        }

        currentNode = currentNode->children[ ascii ];
    }
    currentNode->finish = true;
}

int countWordPaths( Node node ) {
    int counter = 0;

    if ( node.finish ) {
        ++counter;
    }

    for ( int i = 0; i < N; ++i ) {
        if ( node.children[ i ] != NULL ) {
            counter += countWordPaths( *node.children[ i ] );
        }
    }
    return counter;
}

int countPrefixes( Node root, string prefix ) {
    int i, ascii, prefixCount = 0;
    Node currentNode = root;
    
    for ( i = 0; i < prefix.length(); ++i ) {
        ascii = (int)( toupper( prefix[ i ] ) - 'A' );
        if ( currentNode.children[ ascii ] != NULL ) {
            currentNode = ( *currentNode.children[ ascii ] );
        }
        else {
            return 0;
        }
    }

    return countWordPaths( currentNode );
}

bool wordExists( Node root, string word ) {
    int i, ascii;
    Node currentNode = root;
    
    for ( i = 0; i < word.length(); ++i ) {
        ascii = (int)( toupper( word[ i ] ) - 'A' );
        if ( currentNode.children[ ascii ] != NULL ) {
            currentNode = ( *currentNode.children[ ascii ] );
        }
        else {
            return false;
        }
    }

    if ( currentNode.finish ) {
        return true;
    }
    return false;
}

Node* root = initNode( ' ', false );

int main() {
    string prefix = "prefix";
    insertWord( root, "prefixes" ); //+1
    insertWord( root, "prefixos" ); //+1
    insertWord( root, "prefi" );
    insertWord( root, "prefix" ); //+1
    insertWord( root, "prefixed" ); //+1
    insertWord( root, "prefixedd" ); //+1
    printf( "Number of words with prefix '%s': %i\n", prefix.c_str(), countPrefixes( *root, prefix ) );

    string needle = "findme";
    printf( "Word %s exists: %i\n", needle.c_str(), wordExists( *root, needle ) );
    insertWord( root, "findmeplz" );
    printf( "Word %s exists: %i\n", needle.c_str(), wordExists( *root, needle ) );
    insertWord( root, "findme" );
    printf( "Word %s exists: %i\n", needle.c_str(), wordExists( *root, needle ) );

    return 0;
}
