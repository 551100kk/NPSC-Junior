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
        int n;
        scanf("%d", &n);
        int ans = n, mac = 1, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt >= mac) {
                cnt -= mac;
                mac++;
                ans = max(ans, cnt + mac * (n - i));
            } else cnt += mac;
        }
        printf("%d\n", ans);
    }
}
