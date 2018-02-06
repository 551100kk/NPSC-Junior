#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int y, m, d, x, t;
    cin >> y >> m >> d >> x >> t;
    if (x <= 5 && t || x > 5 && !t) puts("happy");
    else puts("unhappy");
}
