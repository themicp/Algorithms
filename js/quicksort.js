function QuickSort( a, start, end ) {
    if ( start >= end ) {
        return a;
    }

    var pIndex = Partition( a, start, end );
    QuickSort( a, start, pIndex - 1 );
    QuickSort( a, pIndex + 1, end );
}

function Partition( a, start, end ) {
    if ( start >= end ) {
        return start;
    }

    var pivot = a[ end ], pIndex = start;
    for ( var i = start; i < end; ++i ) {
        if ( a[ i ] <= pivot ) {
            Swap( a, i, pIndex );
            ++pIndex;
        }
    }

    Swap( a, pIndex, end );

    return pIndex;
}

function Swap( a, i, j ) {
    var temp = a[ i ];
    a[ i ] = a[ j ];
    a[ j ] = temp;
}

var A = [ 7, 2, 1, 6, 8, 5, 3, 4 ];

console.log( A );
QuickSort( A, 0, A.length - 1 );
console.log( A );
