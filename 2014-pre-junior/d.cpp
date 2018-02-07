#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

const int N = 55;
int arr[N][N];
int is[N][N];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int ans;
int n, m;
void dfs (int x, int y, int u, int add) {
    add += arr[x][y];
    if (u == 3) {
        ans = max(ans, add);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X >= 0 & Y >= 0 && X < n && Y < m && is[X][Y] == 0) {
            is[X][Y] = 1;
            dfs(X, Y, u + 1, add);
            is[X][Y] = 0;
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);

        ans = 0;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            is[i][j] = 1;
            dfs(i, j, 0, 0);
            is[i][j] = 0;
        }
        printf("%d\n", ans);
    }
}
