#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>

using namespace std;

#define INF 987654321

FILE *in = fopen( "lis.in", "r" );
int N, L, i, j, *M, *X, *P;

int BS( int L, int key ) {
    int i, j, maxj = 0, mid;
    i = 1; 
    j = N;
    while ( i <= j ) {
        mid = ( i + j )/2;
        if ( X[ M[ mid ] ] < X[ key ] && mid <= L ) {
            maxj = max( maxj, mid );
            i = mid + 1;
        }
        else {
            j = mid - 1;
        }
    }
    return maxj;
}

int main() {
    fscanf( in, "%d", &N );
    M = new int[ N + 1 ];
    X = new int[ N + 1 ];
    P = new int[ N + 1 ];

    for ( i = 1; i <= N; ++i ) {
        fscanf( in, "%d", &X[ i ] );
    }

    L = 0;
    M[ 0 ] = 0;
    X[ 0 ] = INF;
    for ( i = 1; i <= N; ++i ) {
        j = BS( L, i );
        P[ i ] = M[ j ];
        if ( j == L || X[ i ] < ( X[ M[ j + 1 ] ] && M[ j + 1 ] != INF ) ) {
            L = max( L, j + 1 );
            M[ j + 1 ] = i;
        }
    }

    stack< int > res;
    j = M[ L ];
    for ( i = 1; i <= L; ++i ) {
        res.push( X[ j ] );
        j = P[ j ];
    }

    while ( !res.empty() ) {
        printf( "%i ", res.top() );
        res.pop();
    }
    printf( "\n" );

    delete[] M;
    delete[] X;
    delete[] P;

    return 0;
}
