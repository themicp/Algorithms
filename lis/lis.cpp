#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>

using namespace std;

struct Number {
    int value;
    int w;
};

FILE *in = fopen( "lis.in", "r" );
int N, i, j, w, k;
Number *A;
int *seq;
pair< int, int > result;
stack< int > res;

int main() {
    fscanf( in, "%d", &N );
    A = ( Number* )malloc( N * sizeof( Number ) );
    seq = ( int* )malloc( N * sizeof( int ) );
    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%d", &A[ i ].value );
        A[ i ].w = 0;
    }

    for ( i = 0; i < N; ++i ) {
        w = 0;
        k = -1;
        for ( j = 0; j < i; ++j ) {
            if ( A[ i ].value > A[ j ].value ) {
                if ( A[ j ].w + 1 > w ) {
                    k = j;
                    w = A[ j ].w + 1;
                }
            }
        }
        A[ i ].w = max( 1, w );
        seq[ i ] = k;
        if ( A[ i ].w > result.first ) {
            result.first = A[ i ].w;
            result.second = i;
        }
    }
    printf( "%i\n", result.first );
    i = result.second;
    while ( i != -1 ) { 
        res.push( A[ i ].value );
        i = seq[ i ];
    }
    while ( !res.empty() ) {
        printf( "%i ", res.top() );
        res.pop();
    }
    return 0;
}
