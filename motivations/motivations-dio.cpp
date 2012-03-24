#include <cstdio>
#include <cstdlib>
#include <iostream>

/*
Given a non-weightened non-directed graph G = (V, E), return 0
if there are any circles in it, or else find a cut
C = (V1 subset of V, V1' subset of V) such that
there exists no u in V1, v in V1' for which (u, v) in E
*/
using namespace std;

unsigned int N; // |V|
int** E; // set of edges E[ u ][ i ] = x for which (u, x) in E, 1 <= i <= E[ u ][ 0 ]
bool* A; // set of edges in side 1 of the cut, A[ v ] = true iff v in V1
bool* B; // set of edges in side 2 of the cut, B[ v ] = true iff v in V1'
int nA = 0 ; // |A| ; |B| = N - |A|

bool keep_swimming = true; // decides whether we should "just keep swimming"!

// A[ u ] != B[ u ] for every u in E;
// if, during execution for some u in E, A[ u ] = B[ u ] = false,
// the edge hasn't yet been put into one of the two sides

// u : vertex index
// go : traverse all edges connecting u, put them in some side of the cut
// and go() them
void go( int u ) {
        int i;
        int y;
        bool a;

        // cout << "go() on vertex u = " << u << ":\n";
        a = !A[ u ];
        // cout << " (u in " << ( !a? "A)": "B)" ) << "\n";
        // cout << " Connecting with " << E[ u ][ 0 ] << " other vertice(s)\n";
        for( i = 1 ; i <= E[ u ][ 0 ] ; i++ ) {
                y = E[ u ][ i ];
                if( y ) {
                        E[ u ][ i ] = 0;
                        if( !A[ y ] && !B[ y ] ) { // vice-versa edges
                                if( a )
                                        nA++;
                                B[ y ] = !( A[ y ] = a );
                                go( y );
                        }
                        else {
                                if( a != A[ y ] ) {
                                        // woops, there's a cycle in our graph >.<
                                        keep_swimming = false;
                                        break;
                                }
                        }
                }
        }
}

int main() {
        unsigned int i;
        unsigned int j;
        unsigned int x;
        unsigned int y;
        unsigned int M;
        FILE * fi;
        FILE * fo;

        fi = fopen( "motivations.in" , "r" );
        fscanf( fi , "%i\n" , &N );
        A = ( bool* )malloc( sizeof( bool ) * N );
        B = ( bool* )malloc( sizeof( bool ) * N );
        E = ( int** )malloc( sizeof( int* ) * N );
        for( i = 0 ; i < N ; i++ ) {
                A[ i ] = B[ i ] = false;
        }

        for( i = 0 ; i < N ; i++ ) {
                fscanf( fi , "%i %i" , &x , &M );
                E[ i ] = ( int* )malloc( sizeof( int ) * ( M + 1 ) );
                E[ i ][ 0 ] = M;
                for( j = 1 ; j <= M ; j++ ) {
                        fscanf( fi , "%i" , &y );
                        E[ i ][ j ] = y - 1;
                }
        }
        fclose( fi );

        for( i = 0 ; i < N ; i++ ) {
                if( !A[ i ] && !B[ i ] ) {
                        nA++;
                        A[ i ] = true;
                        go( i );
                        if( !keep_swimming )
                                break;
                }
        }

        fo = fopen( "motivations.out" , "w" );
        if( keep_swimming ) {
                fprintf( fo , "%i" , nA );
                for( i = 0 ; i < N ; i++ ) {
                        if( A[ i ] )
                                fprintf( fo , " %i" , i + 1 );
                }
                fprintf( fo , "\n%i" , N - nA );
                for( i = 0 ; i < N ; i++ ) {
                        if( B[ i ] )
                                fprintf( fo , " %i" , i + 1 );
                }
                fprintf( fo , "\n" );
        }
        else {
                fprintf( fo , "0\n0\n" );
        }
        fclose( fo );
        return 0;
}

