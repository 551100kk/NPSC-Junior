#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    vector<par> arr;
    int ma = 0;
    for (int i = 0; i < 6; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        arr.push_back({x, y});
        ma = max(ma, x);
    }
    if (ma != 6 || arr[0].y == 1) puts("Yes");
    else puts("No");
}
