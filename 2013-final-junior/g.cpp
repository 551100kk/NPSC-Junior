#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        map<string, int> ma;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            string item;
            int cost;
            cin >> item >> cost;
            ma[item] = cost;
        }
        int m, ans = 0, flag = 1;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            string item;
            int num;
            cin >> item >> num;
            if (ma.find(item) == ma.end()) flag = 0;
            else ans += ma[item] * num;
        }
        if (!flag) printf("NO ");
        printf("%d\n", ans);
    }
}
