#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    LL x, y;
    scanf("%lld%lld", &x, &y);
    printf("%lld\n", (x + y - 1) / y);
}
