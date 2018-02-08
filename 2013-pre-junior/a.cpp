#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

int main(){
    int t;
    int val[55][55];
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &val[i][j]);
        }
        int tot = 0;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int flag = 1;
            for (int d = 0; d < 4; d++) {
                int x = i + dx[d];
                int y = j + dy[d];
                if (x >= 0 && y >= 0 && x < n && y < m && val[x][y]) flag = 0;
            }
            if (!val[i][j] && flag) tot++;
        }
        printf("%d\n", tot * k + (n * m - tot) * max(0, k - 3));
    }
}
