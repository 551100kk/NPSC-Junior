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
        int n;
        vector<string> arr;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }
        int flag = 1;
        for (int i = 0; i <= n / 2; i++) {
            int is = 0;
            for (auto a: arr[i])
            for (auto b: arr[n - i - 1]) {
                if (a == b) is = 1;
            }
            flag &= is;
        }
        if (flag) puts("Yes");
        else puts("No");
    }
}
