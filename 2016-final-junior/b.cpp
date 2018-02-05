#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
vector<int> pos;
int check (int id, int R) {
    int is[55] = {}, add = 1;
    is[id] = 1;
    queue<par> que;
    que.push({id, R});
    while (que.size()) {
        par out = que.front();
        que.pop();
        for (int i = 0; i < pos.size(); i++) {
            if (is[i]) continue;
            if (abs(pos[i] - pos[out.x]) <= out.y) {
                is[i] = 1, add++;
                que.push({i, out.y - 1});
            }
        }
    }
    return add == pos.size();
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pos.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int l = -1, r = 101, m;
        while (l + 1 != r) {
            m = (l + r) / 2;
            if (check(i, m)) r = m;
            else l = m;
        }
        printf("%d\n", r);
    }
}
