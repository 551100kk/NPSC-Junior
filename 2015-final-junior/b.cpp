#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int n;
    scanf("%d", &n);
    LL ans = 1;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        ans *= x - i;
    }
    printf("%lld\n", ans);
}
