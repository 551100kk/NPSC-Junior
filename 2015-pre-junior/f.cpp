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
        string n;
        int now = 0, m;
        cin >> n >> m;
        for (int i = 0; i < n.size(); i++) {
            now = now * 10 + n[i] - '0';
            now %= m;
        }
        if (now) puts("No");
        else puts("Yes");
    }
}
