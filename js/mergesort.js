function MergeSort( A, start, end ) {
    if ( start >= end ) {
        return [ A[ start ] ];
    }

    var L = MergeSort( A, start, Math.floor( ( start + end )/2 ) );
    var R = MergeSort( A, Math.floor( ( start + end )/2 ) + 1, end );
    var merged = [];
    var i = 0, j = 0;
    while ( i < L.length && j < R.length ) {
        if ( L[ i ] < R[ j ] ) {
            merged.push( L[ i ] );
            ++i;
        }
        else {
            merged.push( R[ j ] );
            ++j;
        }
    }
    if ( i != L.length ) {
        for ( j = i; j < L.length; ++j ) {
            merged.push( L[ j ] );
        }
    }
    else if ( j != R.length ) {
        for ( i = j; i < R.length; ++i ) {
            merged.push( R[ i ] );
        }
    }

    return merged;
}

var A = [ 7, 2, 1, 6, 8, 5, 3, 4 ];
console.log( 'Unsorted: ' + A );
console.log( 'Sorted: ' + MergeSort( A, 0, A.length - 1 ) );
