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
        string a, b;
        cin >> a >> b;
        int flag = 1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '?' && b[i] == '?') flag = 0;
            else if (a[i] == '?') a[i] = b[i];
        }
        if (flag) printf("Yes:%s\n", a.c_str());
        else puts("No");
    }
}
