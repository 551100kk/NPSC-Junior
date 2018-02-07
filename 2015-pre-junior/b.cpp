#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
bool isprime(long long int n) {
    for (LL i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
vector<LL> arr;
void dfs(LL n) {
    if (isprime(n) == 0) return;
    if (n >= 1000000000000000000) return;
    arr.push_back(n);
    for (int i = 0; i < 10; i++) dfs(n * 10 + i);
}
int main() {
    for (int i = 1; i < 10; i++) dfs(i);
    sort(arr.begin(), arr.end());
    int t;
    scanf("%d", &t);
    while (t--) {
        LL l, r;
        scanf("%lld%lld", &l, &r);
        auto pt1 = lower_bound(arr.begin(), arr.end(), l);
        auto pt2 = upper_bound(arr.begin(), arr.end(), r);
        printf("%d\n", pt2 - pt1);
    }
}
