#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> A, B;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        A.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        B.push_back(x);
    }
    LL ans = 0;
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());
    for (int i = 0; i < n; i++) ans += (LL)A[i] * B[i];
    printf("%lld\n", ans);
}
