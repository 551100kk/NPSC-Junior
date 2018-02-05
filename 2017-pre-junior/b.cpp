#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second

int ma[30][30][30];
int is[30][30][30];
int posx[30][30];
int posy[30][30];
int win[30], point[30];

int check (int id) {
    int flag = 0;
    // hor
    for (int i = 0; i < 5; i++){
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            cnt += is[id][i][j];
        }
        if (cnt == 5) flag = 1;
    }
    // vert
    for (int i = 0; i < 5; i++){
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            cnt += is[id][j][i];
        }
        if (cnt == 5) flag = 1;
    }
    // cro1
    int cnt = 0;
    for (int i = 0; i < 5; i++) cnt += is[id][i][i];
    if (cnt == 5) flag = 1;
    // cro2
    cnt = 0;
    for (int i = 0; i < 5; i++) cnt += is[id][i][4 - i];
    if (cnt == 5) flag = 1;
    return flag;
}

vector<int> stu[30];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int a = 0; a < 5; a++)
        for (int b = 0; b < 5; b++) {
            scanf("%d", &ma[i][a][b]);
            posx[i][ma[i][a][b]] = a;
            posy[i][ma[i][a][b]] = b;
        }
    }
    // solve
    for (int i = 0; i < 25; i++) {
        int val;
        scanf("%d", &val);
        for (int j = 0; j < n; j++) {
            int x = posx[j][val];
            int y = posy[j][val];
            is[j][x][y] = 1;
            if (win[j] == 0) point[j]++;
            win[j] = check(j);

        }
    }
    // output
    for (int i = 0; i < n; i++) {
        stu[point[i]].push_back(i);
    }
    for (int i = 0; i <= 25; i++) {
        if (stu[i].size() == 0) continue;
        printf("%d:", i);
        for (auto x: stu[i]) printf(" %d", x + 1);
        puts("");
    }
}
