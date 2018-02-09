#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int a[6], b[6];
        for (int i = 0; i < 6; i++) scanf("%d", &a[i]);
        for (int i = 0; i < 6; i++) scanf("%d", &b[i]);
        int ans = 0;
        for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            if (a[i] > b[j]) ans++;
        }
        printf("%d\n", ans);
    }
}
