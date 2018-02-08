#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
struct P {
    int x, y, z, id;
    int val() {
        return x * 90 + y * 30 + z * 15;
    }
};

int check (P a, P b) {
    if (a.x != b.x) return 0;
    if (a.y != b.y) return 0;
    if (a.z != b.z) return 0;
    return 1;
}

int cmp1 (P a, P b) {
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y > b.y;
    return a.z > b.z;
}
int cmp2 (P a, P b) {
    return a.val() > b.val();
}

const int N = 505;
int pre[N], now[N];

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        vector<P> A, B;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            A.push_back({x, y, z, i});
        }
        B = A;
        sort(A.begin(), A.end(), cmp1);
        sort(B.begin(), B.end(), cmp2);
        int tmp = 1;
        for (int i = 0; i < n; i++) {
            if (i && check(A[i], A[i - 1])) pre[A[i].id] = tmp;
            else {
                tmp = pre[A[i].id] = i + 1;
            }
            //printf("%d...%d\n", A[i].id, pre[A[i].id]);
        }
        tmp = 1;
        for (int i = 0; i < n; i++) {
            if (i && B[i].val() == B[i - 1].val()) now[B[i].id] = tmp;
            else {
                tmp = now[B[i].id] = i + 1;
            }
        }
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (now[i] < pre[i]) a++;
            if (now[i] > pre[i]) b++;
        }
        printf("%d %d\n", a, b);
    }
}
