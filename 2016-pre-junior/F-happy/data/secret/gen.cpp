#include <bits/stdc++.h>
using namespace std;
int main(){
  srand( 514 * 1021 );
  for( int i = 1 ; i <= 7 ; i ++ )
    for( int j = 0 ; j <= 1 ; j ++ ){
      char f[ 99 ] = {};
      sprintf( f , "%d-%d.in" , i , j );
      FILE *fin = fopen( f , "w" );
      int yy = rand() % 9999 + 1;
      if( i == 7 && j == 1 ) yy = 9999;
      int mm = rand() % 12 + 1;
      int dd = rand() % 31 + 1;
      if( mm == 2 ) dd = min( dd , 28 );
      else if( mm == 4 || mm == 6 || mm == 9 || mm == 11 )
        dd = min( dd , 30 );
      fprintf( fin , "%d %d %d %d %d\n" , yy , mm , dd , i , j );
      fclose( fin );
    }
}
