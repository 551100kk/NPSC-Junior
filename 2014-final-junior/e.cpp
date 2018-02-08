#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

char dir[256];

int main(){
    dir['w'] = 0;
    dir['a'] = 1;
    dir['s'] = 2;
    dir['d'] = 3;
    dir['r'] = 1;
    dir['l'] = -1;

    int t;
    scanf("%d", &t);
    while (t--) {
        int now = 0;
        LL x = 0, y = 0;
        char type[5];
        int k, n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s%d", type, &k);
            if (type[0] == 'l' || type[0] == 'r') {
                now += dir[type[0]] * k;
                now = (now % 4 + 4) % 4;
                continue;
            }
            x += dx[(now + dir[type[0]]) % 4] * k;
            y += dy[(now + dir[type[0]]) % 4] * k;
        }
        printf("%lld %lld\n", x, y);
    }
}
