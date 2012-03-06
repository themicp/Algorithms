#include <cstdio>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

const int N = 10000;

string toString( int n ) {
    int i, key;
    char str[ N ];
    string str1 = "";

    i = N - 1;
    if ( n == 0 ) {
        str[ 0 ] = 0 + '0';
        str[ 1 ] = '\0';
        str1 = str;
        return str1;
    }
    while ( n > 0 ) {
        str[ i ] = n%10 + '0';
        n /= 10;
        --i;
    }

    key = 0;
    for ( i = i + 1; i < N; ++i ) {
        str[ key ] = str[ i ];
        ++key;
    }
    str[ key ] = '\0';

    str1 = str;

    return str1;
}

string add( string a, string b ) {
    int i, sum, length, left = 0;

    length = max( (int)a.size(), (int)b.size() );
    if ( length == (int)a.size() ) {
        i = length - (int)b.size();
        while ( i > 0 ) {
            b.insert( 0, "0" );
            --i;
        }
    }
    else {
        i = length - (int)a.size();
        while ( i > 0 ) {
            a.insert( 0, "0" );
            --i;
        }
    }

    string c = "";
    for ( i = length - 1; i >= 0; --i ) {
        sum = ( a[ i ] - '0' ) + ( b[ i ] - '0' ) + left;
        if ( sum > 9 ) {
            c.insert( 0, toString( sum % 10 ) ); 
            left = 1;
        }
        else {
            if ( sum > 9 ) {
                c.insert( 0, toString( sum % 10 ) );
                left = 1;
            }
            else {
                c.insert( 0, toString( sum ) ); 
                left = 0;
            }
        }
    }
    if ( left == 1 ) {
        c.insert( 0, toString( left ) );
    }
    return c;
}

string multiply( string a, string b ) {
    int i, j, left, product;
    string temp = "";
    string c = "";
    for ( i = (int)a.size() - 1; i >= 0; --i ) {
        left = 0;
        temp = "";
        for ( j = (int)a.size() - 1; j > i; --j ) {
            temp.insert( 0, toString( 0 ) );
        }
        for ( j = (int)b.size() - 1; j >=0; --j ) {
            product = ( a[ i ] - '0' ) * ( b[ j ] - '0' ) + left;
            if ( product > 0 ) {
                temp.insert( 0, toString( product % 10 ) );
                left = product/10;
            }
            else {
                temp.insert( 0, toString( product ) );
                left = 0;
            }
        }
        if ( left != 0 ) {
            temp.insert( 0, toString( left ) );
        }
        c = add( c, temp );
    }
    return c;
}

string subtract( string a, string b ) {
    int i, left = 0, j, k;
    string c;
    if ( a.size() < b.size() ) {
        while ( a.size() < b.size() ) {
            a.insert( 0, "0" );
        }
    }
    else {
        while ( b.size() < a.size() ) {
            b.insert( 0, "0" );
        }
    }

    for ( i = (int)a.size() - 1; i >= 0; --i ) {
        j = b[ i ] - '0';
        k = a[ i ] - '0';
        j += left;
        left = 0;
        if ( j > k ) {
            k += 10;
            left = 1;
            if ( i == 0 ) {
                c = "-";
                return c;
            }
        }
        c.insert( 0, toString( k - j ) );
    }
    return c;
}

pair< string, int > divide( string a, string b ) {
    int i, quotient = 0, times;
    string c = b;

    while ( subtract( a, b ) != "-" ) {
        i = 1;
        while ( subtract( c, a ) == "-" ) {
            c = multiply( b, toString( i ) );
            ++i;
        }
        if ( subtract( a, c ) == "-" ) {
            c = multiply( b, toString( i - 2 ) );
            i = i - 1;
        }
        a = subtract( a, c );
        c = b;
        quotient *= 10;
        quotient += i - 1;
    }

    return make_pair( a, quotient );
}

pair< string, int > result;

int main() {
    result = divide( "100", "8" );
    printf( "%s - %i\n", result.first.c_str(), result.second );
    return 0;
}
