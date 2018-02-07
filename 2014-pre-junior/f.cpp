#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

const int N = 100005;
int to[N];

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        string str;
        cin >> str;
        int pre = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] > '9' || str[i] < '0') pre = i - 1;
            else to[i] = pre;
        }
        LL ans = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                if (str[i] == '0') ans++;
                else ans += to[i] - i + 1;
            }
        }
        printf("%lld\n", ans);
    }
}
