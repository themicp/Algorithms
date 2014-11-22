function MergeSort( A ) {
    if ( A.length <= 1 ) {
        return [ A[ 0 ] ];
    }

    return merge( MergeSort( A.slice( 0, Math.floor( A.length/2 ) ) ), MergeSort( A.slice( Math.floor( A.length/2 ), A.length ) ) );
}

function merge( A, B ) {
    var merged = [], i = 0, j = 0;

    while ( i < A.length && j < B.length ) {
        if ( A[ i ] < B[ j ] ) {
            merged.push( A[ i ] );
            ++i;
        }
        else {
            merged.push( B[ j ] );
            ++j;
        }
    }
    if ( i != A.length ) {
        for ( j = i; j < A.length; ++j ) {
            merged.push( A[ j ] );
        }
    }
    else if ( j != B.length ) {
        for ( i = j; i < B.length; ++i ) {
            merged.push( B[ i ] );
        }
    }
    
    return merged;
}

var A = [ 7, 2, 1, 6, 8, 5, 3, 4 ];
console.log( 'Unsorted: ' + A );
console.log( 'Sorted: ' + MergeSort( A ) );
