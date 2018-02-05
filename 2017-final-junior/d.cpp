#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second
vector<int> arr;
int a, b, addx[10], addy[10], num[10];
int flag, ma;

void dfs (int u, int x, int y) {
    if (u == ma + 1) {
        if (x == y) {
            for (int i = 0; i < arr.size(); i++) {
                if (i) putchar(' ');
                if (arr[i] > 0) printf("%d", arr[i]);
                else printf("%d", num[arr[i] * -1]);
            }
            puts("");
            exit(0);
        }
        return;
    }
    for (int i = 1; i <= 10; i++) {
        num[u] = i;
        dfs(u + 1, x + addx[u] * i, y + addy[u] * i);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        arr.push_back(val);
        if (i < n / 2) {
            if (val < 0) {
                ma = max(ma, val * -1);
                addx[val * -1]++;
            }
            else a += val;
        }
        else {
            if (val < 0) {
                ma = max(ma, val * -1);
                addy[val * -1]++;
            }
            else b += val;
        }
    }
    dfs(1, a, b);
    puts("-1");
}
