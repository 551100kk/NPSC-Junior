#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
string str, now;

const int N = 5005;
int dp[N][N];

int solve () {
    int n = str.size();
    int m = now.size();
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if (str[i - 1] == now[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
    }
    return n + m - dp[n][m];
}

int main(){
    int t;
    int ans = -1, id;
    cin >> str >> t;
    for (int i = 0; i < t; i++) {
        cin >> now;
        int len = solve();
        if (ans == -1 || len < ans) ans = len, id = i + 1;
    }
    printf("%d %d\n", id, ans);
}
