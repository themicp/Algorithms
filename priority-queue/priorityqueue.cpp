#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

struct Item {
    int priority;
    int data;
};

struct heapTree {
    Item *items;
    int size;
};

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

void combineDown( heapTree queue, int key, int parent ) {
    int l = key * 2, r = ( key * 2 ) + 1;

    queue.items[ parent ] = queue.items[ key ];
    queue.items[ key ].priority = -1;

    if ( queue.items[ l ].priority > 0 ) {
        if ( queue.items[ l ].priority > queue.items[ r ].priority ) { 
            combineDown( queue, l, key );
        }
    }
    if ( queue.items[ r ].priority > 0 ) {
        if ( queue.items[ r ].priority > queue.items[ l ].priority ) { 
            combineDown( queue, r, key );
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

void deleteMax( heapTree queue ) {
    int l = 1, r = 2, max;

    if ( queue.items[ l ].priority >= queue.items[ r ].priority ) {
        max = l;
    }
    else {
        max = r;
    }

    combineDown( queue, max, 0 );
}

Item max ( heapTree queue ) {
    return queue.items[ 0 ];
}

heapTree queue;

int main() {
    queue.items = ( Item* )calloc( 10000, sizeof( Item ) );
    Item myItem;

    myItem.priority = 2;
    myItem.data = 2;

    print( queue );

    insert( queue, myItem );
    print( queue );

    myItem.priority = 5;
    myItem.data = 5;
    insert( queue, myItem );
    print( queue );

    myItem.priority = 125;
    myItem.data = 125;
    insert( queue, myItem );
    print( queue );

    myItem.priority = 1;
    myItem.data = 124;
    insert( queue, myItem );
    print( queue );

    printf( "Priority: %i, Data: %i\n", max( queue ).priority, max( queue ).data );
    deleteMax( queue );
    print( queue );

    printf( "Priority: %i, Data: %i\n", max( queue ).priority, max( queue ).data );
    deleteMax( queue );
    print( queue );

    if ( isEmpty( queue ) ) {
        printf( "EMPTY\n" );
    }
    else {
        printf( "NOT EMPTY\n" );
    }
    return 0;
}
