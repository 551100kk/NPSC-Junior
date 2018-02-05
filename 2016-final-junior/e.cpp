#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

const int N = 2005;
int dp[N][N], n;
vector<int> A, B;
vector<int> arr;

void build () {
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
    }
}

void solve () {
    int i = n, j = n;
    while (i || j) {
        if (!i) arr.push_back(B[j--]);
        else if (!j) arr.push_back(A[i--]);
        else {
            if (A[i] == B[j]) arr.push_back(A[i--]), j--;
            else {
                if (dp[i - 1][j] > dp[i][j - 1]) arr.push_back(A[i--]);
                else if (dp[i - 1][j] < dp[i][j - 1]) arr.push_back(B[j--]);
                else {
                    if (A[i] < B[j]) arr.push_back(A[i--]);
                    else arr.push_back(B[j--]);
                }
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    A.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        A.push_back(x);
    }
    B = A;
    reverse(B.begin() + 1, B.end());
    build();
    solve();
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (i > arr.size() / 2) arr[i] = arr[arr.size() - i - 1];
        ans ^= arr[i] + i + 1;
    }
    printf("%d\n", ans);
}
