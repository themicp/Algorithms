#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

struct Item {
    int priority;
    int data;
};

int queueSize( Item *queue ) {
    int i, count = 0;
    for ( i = 0; i < 10000; ++i ) {
        if ( queue[ i ].priority != 0 ) {
            ++count;
        }
    }
    return count;
}

void print( Item *queue ) {
    int size = queueSize( queue ), i;

    if ( size == 0 ) {
        printf( "<empty>\n" );
        return;
    }

    for ( i = 0; i < size; ++i ) {
        if ( queue[ i ].priority == -1 ) {
            printf( "NULL " );
        }
        else {
            printf( "%i ", queue[ i ].data );
        }
    }
    printf( "\n" );
}

void swap( Item *queue, int key1, int key2 ) {
    int size = queueSize( queue );

    if ( key1 >= size || key2 >= size || key1 < 0 || key2 < 0 ) {
        printf( "Invalid index key.\n" );
        return;
    }
    Item temp;
    temp = queue[ key1 ];
    queue[ key1 ] = queue[ key2 ];
    queue[ key2 ] = temp;
}

void combineUp( Item *queue, int key ) {
    int parent;
    if ( key == 0 ) {
        return;
    }
    parent = ( key - 1 )/2;

    if ( queue[ key ].priority > queue[ parent ].priority ) {
        swap( queue, key, parent );
        if ( parent > 0 ) {
            combineUp( queue, parent );
        }
    }
}

void combineDown( Item *queue, int key, int parent ) {
    int l = key * 2, r = ( key * 2 ) + 1;

    queue[ parent ] = queue[ key ];
    queue[ key ].priority = -1;

    if ( queue[ l ].priority > 0 ) {
        if ( queue[ l ].priority > queue[ r ].priority ) { 
            combineDown( queue, l, key );
        }
    }
    if ( queue[ r ].priority > 0 ) {
        if ( queue[ r ].priority > queue[ l ].priority ) { 
            combineDown( queue, r, key );
        }
    }
}

void insert( Item *queue, Item item ) {
    int size = queueSize( queue );
    
    queue[ size ] = item;

    combineUp( queue, size );
}

bool isEmpty( Item *queue ) {
    return !( queueSize( queue ) > 0 );
}

void deleteMax( Item* queue ) {
    int l = 1, r = 2, max;

    if ( queue[ l ].priority >= queue[ r ].priority ) {
        max = l;
    }
    else {
        max = r;
    }

    combineDown( queue, max, 0 );
}

Item max ( Item *queue ) {
    return queue[ 0 ];
}

Item *queue;

int main() {
    queue = ( Item* )calloc( 10000, sizeof( Item ) );
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
