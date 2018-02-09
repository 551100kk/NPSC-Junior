#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

char s[105][105];
int is[105][105];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

int leaf = 0, n, m;

int check (int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X >= 0 && Y >= 0 && X < n && Y < m && s[X][Y] == '#')
            cnt++;
    }
    if (cnt == 1) return 1;
    return 0;
}

void dfs (int x, int y) {
    if (isalpha(s[x][y])) leaf += check(x, y);
    for (int i = 0; i < 4; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X >= 0 && Y >= 0 && X < n && Y < m && s[X][Y] != '.' && is[X][Y] == 0) {
            is[X][Y] = 1;
            dfs(X, Y);
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", s[i]);
        memset(is, 0, sizeof(is));
        int ans = 0;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (is[i][j] || s[i][j] == '.') continue;
            is[i][j] = 1;
            leaf = 0;
            dfs(i, j);
            ans += (leaf + 1) / 2;
        }
        printf("%d\n", ans);
    }
}
