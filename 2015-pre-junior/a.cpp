#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int n, x, y;
    cin >> n >> x >> y;
    int pos[3] = {};
    pos[n] = 1;
    swap(pos[x], pos[y]);
    for (int i = 1; i <= 3; i++) {
        if (pos[i]) printf("%d\n", i);
    }
}
