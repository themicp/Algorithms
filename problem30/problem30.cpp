#include <cstdio>
#include <string>

using namespace std;

int j, a[ 9 ], S;
unsigned long long int i;

int pow ( int n, int times ) {
    int i, res = 1;
    for ( i = 0; i < times; ++i ) {
        res *= n;
    }
    return res;
}

bool sumCheck( unsigned long long int n ) {
    int k, sum = 0;
    unsigned long long int j = n;
    while ( j > 0 ) {
        k = j % 10;
        j /= 10;
        sum += k > 0 ? a[ k - 1 ] : 0;
    }
    if ( sum == n ) {
        return true;
    }
    return false;
}

int main() {
    for ( i = 0; i < 9; ++i ) {
        a[ i ] = pow( i + 1, 5 );
    }
    for ( i = 2; i < 1000000000000000000; ++i ) {
        if ( sumCheck( i ) ) {
            S += i;;
            printf( "%i - %lli\n", S, i );
        }
    }
    printf( "%i\n", S );
    return 0;
}
