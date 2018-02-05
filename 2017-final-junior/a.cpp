#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t <= x) {
        printf("%d 0\n", t);
    }
    else {
        int ans1 = x;
        int ans2 = t / x;
        if (t % x < y) {
            ans1 += (x - y) * (t / x - 1);
            ans2--;
        }
        else {
            ans1 += (x - y) * (t / x - 1);
            ans1 += t % x - y;
        }
        printf("%d %d\n", ans1, ans2);
    }
}
