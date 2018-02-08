#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

int coin[7] = {1, 5, 10, 50, 100, 500, 1000};
int val[7];

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int tot = 0, cnt = 0, ans = 0;
        for (int i = 0; i < 7; i++) {
            scanf("%d", &val[i]);
            cnt += val[i];
            tot += val[i] * coin[i];
        }
        tot -= n;
        for (int i = 6; i >= 0; i--) {
            while (tot >= coin[i] && val[i]) tot -= coin[i], val[i]--, ans++;
        }
        if (tot == 0) printf("%d\n", cnt - ans);
        else puts("OAQ");

    }
}
