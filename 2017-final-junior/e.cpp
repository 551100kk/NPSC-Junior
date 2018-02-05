#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second

const int N = 100005;
int is[105];
vector<int> prime;
int add[N][30];
int need[30], pt[30];

int main(){
    for (int i = 2; i < 100; i++) {
        if (is[i]) continue;
        prime.push_back(i);
        for (int j = i + i; j < 100; j += i)
            is[j] = 1;
    }
    int cnt = prime.size();
    int n, m;
    scanf("%d%d", &n, &m);
    int tmp = m;
    for (int i = 0; i < cnt; i++) {
        while (tmp % prime[i] == 0) {
            tmp /= prime[i];
            need[i]++;
        }
    }

    LL ans = 0;
    int now = 1;
    for (int i = 1; i <= n; i++) {
        int val, mi = 1000000;
        scanf("%d", &val);
        now = now * val % m;
        for (int j = 0; j < cnt; j++) {
            add[i][j] = add[i - 1][j];
            while (val % prime[j] == 0) {
                val /= prime[j];
                add[i][j]++;
            }
            while (pt[j] + 1 < i && add[i][j] - add[pt[j] + 1][j] >= need[j]) pt[j]++;
            mi = min(mi, pt[j]);
        }
        if (now == 0) ans += mi + 1;
        //printf("(%d)\n", ans);
    }
    printf("%lld\n", ans);
}
