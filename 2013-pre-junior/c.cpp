#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

LL solve_two (LL n, LL m, LL I) {
    LL mi = min(min(n, m), I);
    LL ma = min(min(n - mi, m), I);
    LL tot = ma * mi;
    tot += (ma + mi - 1) * (mi - ma) / 2;
    return tot;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        LL n, m;
        cin >> n >> m;
        LL mi = min(n, m);
        LL ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
        // ans1
        for (LL i = 1; i < mi; i++) {
            LL x = min(i - 1, n - i);
            LL y = min(i - 1, m - i);
            LL z = min(min(n - i, m - i) , i - 1);
            ans1 += solve_two(n, m - i, i - 1) * x;
            ans1 += solve_two(m, n - i, i - 1) * y;
            ans1 -= x * y * z;
        }
        ans1 *= 4;
        // ans2
        for (LL i = 1; i < mi; i++) {
            if (i + i <= n) ans2 += solve_two(n, m - i, i - 1);
            if (i + i <= m) ans2 += solve_two(m, n - i, i - 1);
            if (i + i <= n || i + i <= m) {
                LL tmp = min(min(n - i, m - i), i - 1);
                ans2 += tmp * tmp;
            }
        }
        ans2 *= 2;
        // ans3 & 4
        for (LL i = 1; i < mi; i++) {
            if (i + i <= n && i + i <= m) ans3 += min(min(n - i, m - i), i - 1), ans4++;
        }
        ans3 *= 4;
        printf("%lld\n", ans1 + ans2 + ans3 + ans4);
    }
}
