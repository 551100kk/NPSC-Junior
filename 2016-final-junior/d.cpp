#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
const int N = 1000005;
int val[N], pos[N], n;

LL solve1 (int x, int y) {
    int now = 0;
    LL add = 0;
    while (x != y) {
        int nxt = pos[x];
        add += (nxt - now + n) % n;
        now = nxt;
        x = (x + 1) % n;
    }
    return add + 1;
}

LL solve2 (int x, int y) {
    int now = 0;
    LL add = 0;
    while (x != y) {
        int nxt = pos[(x + n - 1) % n];
        add += (nxt - now + n) % n;
        now = nxt;
        x = (x + n - 1) % n;
    }
    return add + 1;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        val[i] = x - 1;
        pos[x - 1] = i;
    }
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    printf("%lld\n", min(solve1(x, y), solve2(x, y)));
}
