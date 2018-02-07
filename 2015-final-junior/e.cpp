#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    LL a, n;
    cin >> a >> n;
    if (a == 0 || n == 0 || a == 1) {
        puts("-1");
        return 0;
    }
    LL tmp = 1, ans = 0;
    while (n >= a) {
        ans++;
        n /= a;
    }
    cout << ans << endl;
}
