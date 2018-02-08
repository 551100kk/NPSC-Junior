#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

int dp[105][2];

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + x;
            if (i == 1) dp[i][0] = -123456789;
        }
        printf("%d\n", max(dp[n][0], dp[n][1]));
    }
}
