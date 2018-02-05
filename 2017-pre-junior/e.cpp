#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 0; i < m; i++) {
        int id;
        scanf("%d", &id);
        if (x < y) {
            if (id > x && id < y) x++, y--;
            else x--, y++;
        }
        else {
            if (id > y && id < x) y++, x--;
            else x++, y--;
        }

        if (x == 0) x = n;
        else if (x == n + 1) x = 1;
        if (y == 0) y = n;
        else if (y == n + 1) y = 1;

        printf("%d %d\n", x, y);
    }
}
