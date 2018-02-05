#include <bits/stdc++.h>
using namespace std;
char fname[ 99 ];
set< vector<int> > S;
int main(){
  srand( 514 * 1021 );
  for( int i = 1 ; i <= 4 ; i ++ )
    for( int j = 1 ; j <= 4 ; j ++ )
      for( int k = 1 ; k <= 4 ; k ++ ){
        if( i + j + k == 3 ) continue;
        vector< int > v = { i , j , k };
        sort( v.begin() , v.end() );
        if( v[ 0 ] + v[ 1 ] <= v[ 2 ] ) continue;
        S.insert( { i , j , k } );
        sprintf( fname , "small-%d-%d-%d.in" , i , j , k );
        FILE *f = fopen( fname , "w" );
        fprintf( f , "%d %d %d\n" , i , j , k );
        fclose( f );
      }
  for( int i = 998 ; i <= 1000 ; i ++ )
    for( int j = 998 ; j <= 1000 ; j ++ )
      for( int k = 998 ; k <= 1000 ; k ++ ){
        vector< int > v = { i , j , k };
        sort( v.begin() , v.end() );
        if( v[ 0 ] + v[ 1 ] <= v[ 2 ] ) continue;
        S.insert( { i , j , k } );
        sprintf( fname , "large-%d-%d-%d.in" , i , j , k );
        FILE *f = fopen( fname , "w" );
        fprintf( f , "%d %d %d\n" , i , j , k );
        fclose( f );
      }
  for( int i = 0 ; i < 30 ; i ++ ){
    vector< int > v = { 0 , 0 , 0 };
    while( true ){
      for( int j = 0 ; j < 3 ; j ++ )
        v[ j ] = rand() % 1000 + 1;
      sort( v.begin() , v.end() );
      if( v[ 0 ] + v[ 1 ] <= v[ 2 ] )
        continue;
      random_shuffle( v.begin() , v.end() );
      if( S.count( { v[ 0 ] , v[ 1 ] , v[ 2 ] } ) )
        continue;
      break;
    }
    S.insert( { v[ 0 ] , v[ 1 ] , v[ 2 ] } );
    sprintf( fname , "random-%d.in" , i );
    FILE *f = fopen( fname , "w" );
    fprintf( f , "%d %d %d\n" , v[ 0 ] , v[ 1 ] , v[ 2 ] );
    fclose( f );
  }
}
