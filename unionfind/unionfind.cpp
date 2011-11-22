#include <cstdio>

using namespace std;

struct Node {
    Node* parent;
    int population;
    char *name;
    int size;
};

typedef Node nodeGroup;

nodeGroup makeGroup( Node &element ) {
    element.parent = NULL;
    element.size = 1;
    return element;
}

nodeGroup find( Node element ) {
    while ( element.parent != NULL ) {
        element = *element.parent;
    }

    return element;
}

nodeGroup unionSet( nodeGroup A, nodeGroup B ) {
    if ( A.size >= B.size ) {
        B.parent = &A;
        A.size += B.size;
        return A;
    }
    A.parent = &B;
    B.size += A.size;

    return B;
}

int main() {
    return 0;
}
