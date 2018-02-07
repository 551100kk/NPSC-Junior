#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
vector<int> A, B;
vector<int> arr;
int flag;
void dfs (int u) {
    if (u == 6) {
        int add1 = 0;
        int add2 = 0;
        for (auto x: A) add1 += x;
        for (auto x: B) add2 += x;
        if (A.size() == 3 && B.size() == 3
                && add1 - A.back() > A.back()
                && add2 - B.back() > B.back()) flag = 1;
        return;
    }
    A.push_back(arr[u]);
    dfs(u + 1);
    A.pop_back();
    B.push_back(arr[u]);
    dfs(u + 1);
    B.pop_back();
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        arr.clear();
        int x;
        for (int i = 0; i < 6; i++) {
            scanf("%d", &x);
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        flag = 0;
        dfs(0);
        if (flag) puts("Yes");
        else puts("No");
    }
}
