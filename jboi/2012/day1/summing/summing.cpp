#include <cstdio>
#include <queue>
#include <map>
#include <list>

using namespace std;

FILE *in = fopen( "in", "r" ), *out = fopen( "out", "w" );
int N, Q, i, j, v, p, t, maxsum, current;
queue< int > start, target;
map< int, list< pair< int, int > > > A;
list< pair< int, int > >::iterator it;

int sum ( int current, int next, int target ) {
    list< pair< int, int > >::iterator it;
    int maxsum = current, value, temp, tempsum;
    if ( ( int )A[ next ].size() == 0 ) {
        return current;
    }
    for ( it = A[ next ].begin(); it != A[ next ].end(); ++it ) {
        tempsum = current;
        value = ( *it ).first;
        if ( tempsum + value < target ) {
            tempsum = max( tempsum, tempsum + value );
            temp = sum( tempsum, ( *it ).second, target );
            if ( temp == target ) {
                return target;
            }
            if ( temp < target ) {
                maxsum = max( maxsum, max( tempsum, temp ) );
            }
        }
        else if ( tempsum + value == target ) {
            return target;
        }
    }
    return maxsum;
}

int main() {
    fscanf( in, "%i %i", &N, &Q );

    for ( i = 0; i < N; ++i ) {
        fscanf( in, "%i %i", &v, &p );
        if ( p == -1 ) {
            start.push( i );
        }
        A[ p ].push_back( make_pair( v, i ) );
    }

    for ( i = 0; i < Q; ++i ) {
        fscanf( in, "%i", &t );
        target.push( t );
    }

    while ( !target.empty() ) {
        maxsum = 0;
        for ( it = A[ -1 ].begin(); it != A[ -1 ].end(); ++it ) {
            current = sum( ( *it ).first, ( *it ).second, target.front() );
            if ( current <= target.front() ) {
                maxsum = max( maxsum, current );
            }
        }
        if ( maxsum == 0 ) {
            fprintf( out, "none\n", maxsum );
        }
        else {
            fprintf( out, "%i\n", maxsum );
        }
        target.pop();
    }

    return 0;
}
