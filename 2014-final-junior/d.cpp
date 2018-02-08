#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

const int N = 1000005;
vector<int> fac[N];
int is[N];

int main(){
    for (int i = 2; i < N; i++) {
        if (is[i]) continue;
        for (int j = i; j < N; j += i) {
            is[j] = 1;
            fac[j].push_back(i);
        }
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        set<int> bst;
        int n;
        scanf("%d", &n);
        int flag = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (flag) continue;
            for (auto pri: fac[x]) {
                if (bst.find(pri) != bst.end()) flag = 1;
                bst.insert(pri);
            }
        }
        if (flag) puts("Yes");
        else puts("No");
    }
}
