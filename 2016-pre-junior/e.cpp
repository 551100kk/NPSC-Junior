#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
const int N = 100005;
char s[N];
int main(){
    int n;
    scanf("%d%s", &n, s);
    int mi = 0, id = -1;
    int add = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 's') add++;
        else add--;
        if (add < mi) mi = add, id = i;
    }
    int flag = 1;
    add = 0;
    for (int i = id + 1; i < n; i++) {
        if (s[i] == 's') add++;
        else add--;
        if (add < 0) flag = 0;
    }
    for (int i = 0; i <= id; i++) {
        if (s[i] == 's') add++;
        else add--;
        if (add < 0) flag = 0;
    }
    if (flag) printf("%d\n", id + 1);
    else puts("-1");
}
