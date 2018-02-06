#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXT = 500;
const int MAXN = 100;
const int MAXM = 10000;
const int MAXV = 100000001;
int main(){
  srand( 514514 );
  printf( "%d\n" , MAXT );
  int n = 60 , m , k = 1 ;
  for( int i = 0 ; i < MAXT ; i ++ ){
    n = rand() % 81 + 20 ;
    m = rand() % ( MAXM - n ) + n ;
    k = rand() % n + 1 ;
    printf( "%d %d %d\n" , n , m , k ) ;
  }
}
