#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

string item[105];
int cnt[105];

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            cin >> item[i] >> cnt[i];
        }
        for (int i = 0; i < m; i++) {
            int k;
            scanf("%d", &k);
            set<string> bst;
            while (k--) {
                string tmp;
                cin >> tmp;
                bst.insert(tmp);
            }
            for (int i = 0; i < n; i++) {
                if (bst.find(item[i]) == bst.end()) cnt[i]--;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > 0) ans++;
        }
        if (ans) printf("%d\n", ans);
        else puts("Need to be lucky");
    }
}
