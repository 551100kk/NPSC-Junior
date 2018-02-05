#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

char s[305];

int check (int l, int r) {

    int len = (r - l + 1) / 4;
    int flag = 1;
    for (int i = 0; i < len; i++) {
        if (s[l + i] != s[l + i + len] || s[l + i] != s[l + i + len * 3]) {
            // printf("%c%c%c\n", s[l+i], s[l+i+len], s[l+i+len*3]);
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
    int n;
    scanf("%s", s);
    n = strlen(s);

    string out;
    for (int i = 0; i < n; i++) {
        string now;
        for (int j = i + 3; j < n; j += 4) {
            for (int a = 0; a < 4; a++) now.push_back(s[j - (3 - a)]);
            if (check(i, j)) {
                if (now.size() > out.size()
                        || now.size() == out.size() && now < out) out = now;
            }
        }
    }
    if (out.empty()) puts("===>{*}(*)<===");
    else puts(out.c_str());
}
