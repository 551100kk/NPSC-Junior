#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
const int N = 100005;
LL add[N];
int main(){
    int n;
    LL k;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &add[i]);
        add[i] += add[i - 1];
    }
    k = (LL)n * (n + 1) / 2 - k + 1;
    LL l = -1, r = 12345678987654321LL, m;
    while (l + 1 != r) {
        m = (l + r) / 2;
        LL tot = 0;
        for (int i = 1, j = 0; i <= n; i++) {
            while (add[i] - add[j] > m) j++;
            tot += i - j;
        }
        if (tot >= k) r = m;
        else l = m;
    }
    printf("%lld\n", r);
}
