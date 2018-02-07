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
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            arr.push_back(x);
        }
        int ans = n;
        if (n == 1) ans = 0;
        for (int i = 0; i < n; i++) {
            map<par, int> ma;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int x = j - i;
                int y = arr[j] - arr[i];
                int gcd = __gcd(x, y);
                x /= gcd;
                y /= gcd;
                if (x < 0) x *= -1, y *= -1;
                ma[par({x, y})]++;
            }
            for (auto pt: ma) {
                ans = min (ans, n - 1 - pt.second);
            }
        }
        printf("%d\n", ans);
    }
}
