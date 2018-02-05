#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

int n, m, ans;
void dfs (int u, int add) {
    if (u == n) {
        if (add == m) ans++;
        return;
    }
    for (int i = 1; i <= 6; i++) dfs(u + 1, add + i);
}

int main(){
    scanf("%d%d", &n, &m);
    dfs(0, 0);
    printf("%d\n", ans);
}
