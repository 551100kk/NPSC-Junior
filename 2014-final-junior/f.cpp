#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int t, C = 0;
    scanf("%d", &t);
    while (t--) {
        int n;
        LL m, ma = 0, tot = 0;
        cin >> n >> m;
        m = abs(m);
        vector<LL> arr;
        for (int i = 0; i < n; i++) {
            LL x;
            cin >> x;
            arr.push_back(x);
            tot += x;
            ma = max(ma, x);
        }

        if (m == 0) {
            puts("0");
            continue;
        }

        if (ma <= m) {
            int ans = m / tot * n;
            m %= tot;
            for (int i = 0; i < n && m > 0; i++) {
                m -= arr[i];
                ans++;
            }
            printf("%d\n", ans);
            continue;
        }

        int ans = 0, flag = 1;
        ma = m, tot = m;
        while (flag) {
            for (int i = 0; i < n && flag; i++){
                ans++;
                tot += arr[i];
                ma = max(ma, arr[i]);
                if (tot - ma >= ma) flag = 0;
            }
        }
        printf("%d\n", ans);
    }
}
