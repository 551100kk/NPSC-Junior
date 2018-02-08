#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        LL n, m;
        cin >> m >> n;
        LL cnt = (n - 1) / m;
        LL ans = (n + 1) * n / 2;
        ans += cnt * n - m * (1 + cnt) * cnt / 2;
        printf("%lld\n", ans);
    }
}
