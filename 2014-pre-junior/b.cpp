#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

const int N = 100005;
int Left[N], Right[N];

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
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
        int id = -1;
        for (int i = 0; i < m; i++) {
            if (id + 1 < n && A[id + 1] == B[i]) id++;
            Left[i] = id;
        }
        id = n;
        for (int i = m - 1; i >= 0; i--) {
            if (id > 0 && A[id - 1] == B[i]) id--;
            Right[i] = id;
        }
        Right[m] = n;
        // all
        if (Right[0] <= 1) {
            puts("1");
            continue;
        }
        int ans = -1;
        for (int i = 0; i < m; i++) {
            if (Right[i + 1] - Left[i] <= 2) {
                if (ans == -1 || Left[i] + 2 < ans)
                    ans = Left[i] + 2;
            }
        }
        printf("%d\n", ans);

    }
}
