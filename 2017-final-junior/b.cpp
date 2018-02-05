#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second
vector<int> arr[60];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 999999; i++) {
        int x = n, y = i;
        int add[10] = {}, flag = 1;
        for (int j = 0; j < 6; j++) {
            if (add[y % 10]++) flag = 0;
            y /= 10;
        }
        if (!flag) continue;
        y = i;
        int cnt = 0;
        for (int j = 0; j < 6; j++) {
            int a = x % 10;
            int b = y % 10;
            x /= 10;
            y /= 10;
            int dis = abs(a - b);
            cnt += min(dis, 10 - dis);
        }
        arr[cnt].push_back(i);
    }
    for (int i = 0; i < 60; i++) {
        if (arr[i].size()) {
            printf("%d %d\n", (int)arr[i].size(), i);
            for (int j = 0; j < arr[i].size(); j++) {
                if (j) putchar(' ');
                printf("%06d", arr[i][j]);
            }
            puts("");
            break;
        }
    }
}
