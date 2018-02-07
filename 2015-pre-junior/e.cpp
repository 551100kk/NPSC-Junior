#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int t;
    string str;
    cin >> t;
    while (t--) {
        cin >> str;
        str = str + str;
        int ans = 0;
        for (int i = 0; i < str.size() / 2; i++) {
            int ch[26] = {};
            for (int j = 0; j < 26 && j < str.size(); j++) {
                if (ch[str[i + j] - 'A']++) break;
                ans = max(ans, j + 1);
            }
        }
        printf("%d\n", ans);
    }
}
