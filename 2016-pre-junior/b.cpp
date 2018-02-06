#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int n;
    string str;
    int pos;
    cin >> n >> str >> pos;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (i == pos - 1) continue;
        if (str[i] == 'M' && ans.size() < n - 2) ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i) putchar(' ');
        printf("%d", ans[i] + 1);
    }
    puts("");
}
