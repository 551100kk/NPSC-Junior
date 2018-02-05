#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

const int N = 2005;
char in[N];
vector<string> A, B;

int check (string str) {
    if (str[0] == '+' || str[0] == '-') str.erase(str.begin());
    if (str.size() == 0) return 0;
    int dot = -1, dotcnt = 0;
    int exp = -1, expcnt = 0;
    int flag = 1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '+' || str[i] == '-') {
            if (i + 1 == str.size() || (str[i + 1] < '0' || str[i + 1] > '9'))
                return 0;
        }
    }
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'E') str[i] = 'e';
        if (str[i] == '.') dot = i, dotcnt++;
        else if (str[i] == 'e') {
            exp = i, expcnt++;
            if (i + 1 < str.size() && str[i + 1] == '+') str[i + 1] = '0';
            if (i + 1 < str.size() && str[i + 1] == '-') str[i + 1] = '0';
        }
        else {
            if (str[i] < '0' || str[i] > '9') flag = 0;
        }
    }
    if (dotcnt > 1 || expcnt > 1 || flag == 0) return 0;
    if (dotcnt == 0 && expcnt == 0) return 2;
    if (dotcnt == 1 && expcnt == 0) {
        if (str.size() > 1) return 1;
        else return 0;
    }
    if (dotcnt == 0 && expcnt == 1) {
        if (exp > 0 && exp + 1 < str.size()) return 1;
        else return 0;
    }

    if (dot > exp) return 0;
    if (dot == 0 && exp == 1) return 0;
    if (exp + 1 == str.size()) return 0;
    return 1;
}

int main(){
    //freopen("in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 0; i < n; i++) {
        fgets(in, N, stdin);
        istringstream str(in);
        string tmp;
        while (str >> tmp) {
            A.push_back(tmp);
        }
    }
    for (int i = 0; i < m; i++) {
        fgets(in, N, stdin);
        istringstream str(in);
        string tmp;
        while (str >> tmp) {
            B.push_back(tmp);
        }
    }
    while (A.size() < B.size()) A.push_back("<missing>");
    while (A.size() > B.size()) B.push_back("<missing>");
    n = A.size();
    for (int i = 0; i < n; i++) {
        int a = check(A[i]);
        int b = check(B[i]);
        if (a && b && b == 1) printf("%s %s float\n", A[i].c_str(), B[i].c_str());
        else printf("%s %s str\n", A[i].c_str(), B[i].c_str());
    }
}
