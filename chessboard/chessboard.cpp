#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int w ( int* C, int mu ) {
    int i, profit = 0;
    for ( i = 0; i < 4; ++i ) {
        if ( (int)pow( (double)2, i ) & mu ) {
            profit += C[ 3 - i ];
        }
    }
    return profit;
}

FILE *in = fopen( "chessboard.in", "r" );
int W[ 2 ][ 8 ], C[ 4 ], parity = 1, method, i, omega, j, mu, profit, solution, N, M[] = { 0, 1, 2, 4, 5, 8, 9, 10 }; //Encoding column methods as binary numbers to be able to do bitwise operators.

int main() {
    fscanf( in, "%i", &N );
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < 4; ++j ) {
            fscanf( in, "%i", &C[ j ] );
        }
        for ( omega = 0; omega < 8; ++omega ) {
            profit = 0;
            for ( mu = 0; mu < 8; ++mu ) {
                if ( !( M[ omega ] & M[ mu ] ) ) {
                    profit = max( profit, W[ !parity ][ mu ] );
                }
            }
            profit += w( C, M[ omega ] );
            W[ parity ][ omega ] = profit;
        }
        parity = !parity;
    }
    for ( i = 0; i < 8; ++i ) {
        solution = max( solution, W[ !parity ][ i ] );
    }
    printf( "Solution: %i\n", solution );
    return 0;
}
