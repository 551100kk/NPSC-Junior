#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second

const int N = 1000005;
LL R1[N];
map<LL, int> cnt;
int main(){
    random_device rd;
    mt19937_64 eng(rd());
    uniform_int_distribution<LL> distr;
    for (int i = 1; i < N; i++) {
        R1[i] = distr(eng);
    }

    LL pre = 0, ans = 0;
    cnt[pre] = 1;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        pre ^= R1[val];
        ans += cnt[pre]++;
    }
    printf("%lld\n", ans);
}
