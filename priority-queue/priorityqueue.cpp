#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

struct Item {
    unsigned long long int int priority;
    unsigned long long int int data;
};

struct heapTree {
    Item *items;
    unsigned long long int size;
};

heapTree newTree() {
    heapTree queue;

    queue.items = ( Item* )calloc( 10000, sizeof( Item ) );
    queue.size = 0;

    return queue;
}

void print( heapTree queue ) {
    int size = queue.size;
    int i;

    if ( size == 0 ) {
        printf( "<empty>\n" );
        return;
    }

    for ( i = 0; i < size; ++i ) {
        if ( queue.items[ i ].priority == -1 ) {
            printf( "NULL " );
        }
        else {
            printf( "%i ", queue.items[ i ].data );
        }
    }
    printf( "\n" );
}

void swap( heapTree queue, int key1, int key2 ) {
    int size = queue.size;

    if ( key1 >= size || key2 >= size || key1 < 0 || key2 < 0 ) {
        printf( "Invalid index key.\n" );
        return;
    }
    Item temp;
    temp = queue.items[ key1 ];
    queue.items[ key1 ] = queue.items[ key2 ];
    queue.items[ key2 ] = temp;
}

void combineUp( heapTree queue, int key ) {
    int parent;
    if ( key == 0 ) {
        return;
    }
    parent = ( key - 1 )/2;

    if ( queue.items[ key ].priority > queue.items[ parent ].priority ) {
        swap( queue, key, parent );
        if ( parent > 0 ) {
            combineUp( queue, parent );
        }
    }
}

void combineDown( heapTree queue, int key ) {
    int l = key * 2, r = ( key * 2 ) + 1;

    if ( key == 0 ) {
        l = 1;
        r = 2;
    }

    if ( queue.items[ l ].priority > 0 ) {
        if ( queue.items[ l ].priority >= queue.items[ r ].priority ) {
            swap( queue, l, key );
            combineDown( queue, l );
        }
    }
    if ( queue.items[ r ].priority > 0 ) {
        if ( queue.items[ r ].priority > queue.items[ l ].priority ) {
            swap( queue, r, key );
            combineDown( queue, r );
        }
    }
}

void insert( heapTree &queue, Item item ) {
    int size = queue.size;

    queue.items[ size ] = item;
    ++queue.size;

    combineUp( queue, size );
}

bool isEmpty( heapTree queue ) {
    return !queue.size > 0;
}

void deleteMax( heapTree &queue ) {
    if ( queue.size == 0 ) {
        printf( "No more elements to delete.\n" );
        return;
    }
    queue.items[ 0 ] = queue.items[ queue.size - 1 ];

    queue.items[ queue.size - 1 ].priority = -1;
    --queue.size;

    combineDown( queue, 0 );
}

Item max ( heapTree queue ) {
    return queue.items[ 0 ];
}

heapTree queue;

int main() {
    queue = newTree();
    Item myItem;

    myItem.priority = 2;
    myItem.data = 2;

    print( queue );

    insert( queue, myItem );
    print( queue );

    if ( isEmpty( queue ) ) {
        printf( "EMPTY\n" );
    }
    else {
        printf( "NOT EMPTY\n" );
    }
    return 0;
}
