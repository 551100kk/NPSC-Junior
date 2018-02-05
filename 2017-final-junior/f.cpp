#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", abs(k - (n - k)));
}
