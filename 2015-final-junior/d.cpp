#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    LL n, ans = 0;
    cin >> n;
    for (LL i = 1, j = n; i < n; i++) {
        while (i * i + j * j > n * n) j--;
        ans += j;
    }
    ans = ans * 4 + n * 4 + 1;
    cout << ans << endl;
}
