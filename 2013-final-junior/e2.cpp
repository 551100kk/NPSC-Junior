#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

LL num (LL n) {
    LL l = 0, r = n + 1;
    while (l + 1 != r) {
        LL m = (l + r) / 2;
        if (m * (m + 1) / 2 > n) r = m;
        else l = m;
    }
    return l * (l + 1) / 2;
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        LL n;
        scanf("%lld", &n);
        int ans = 0;
        LL tmp = n;
        while (tmp) {
            LL res = num(tmp);
            tmp -= res;
            if (tmp) tmp += n;
            ans++;
        }
        printf("%d\n", ans);
    }
}
