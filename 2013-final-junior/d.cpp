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
        int n, a, b;
        cin >> n >> a >> b;
        int ans = n;
        for (int i = 0; i <= n; i++) {
            int x = i;
            int y = n - i;
            int add = n;
            while (x >= a || y >= b) {
                if (x >= a) {
                    add += x / a;
                    y += x / a;
                    x %= a;
                }
                if (y >= b) {
                    add += y / b;
                    x += y / b;
                    y %= b;
                }
            }
            ans = max(ans, add);
        }
        printf("%d\n", ans);
    }
}
