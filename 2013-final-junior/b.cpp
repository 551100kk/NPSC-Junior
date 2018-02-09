#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

const int N = 100005;
int pre[N], to[N], is[N];
int val[N];

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, mi = -1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &to[i]);
            pre[to[i]] = i;
            is[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &val[i]);
            if (mi == -1 || val[i] < mi) mi = val[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (is[i] || to[i] == i) continue;
            int tot = 0;
            int cnt = 0;
            int now = -1;
            int id = i;
            do {
                is[id] = 1;
                tot += val[id];
                cnt++;
                if (now == -1 || val[id] < now) now = val[id];
                id = to[id];
            } while (id != i);
            ans += min(tot + (cnt - 2) * now, tot + mi * 2 + now + (cnt - 1) * mi);
        }
        printf("%d\n", ans);
    }
}
