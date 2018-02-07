#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int n;
    scanf("%d", &n);
    vector<par> arr;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        arr.push_back({x, y});
    }
    vector<int> ans;
    for (int i = 2; i < n; i++) {
        int x1 = arr[i].x - arr[i - 1].x;
        int y1 = arr[i].y - arr[i - 1].y;
        int x2 = arr[i - 1].x - arr[i - 2].x;
        int y2 = arr[i - 1].y - arr[i - 2].y;
        if (x1 * y2 - x2 * y1 || x1 * x2 + y1 * y2 < 0) ans.push_back(i);
    }

    printf("%d\n", (int) ans.size());
    for (auto x: ans) printf("%d\n", x);
}
