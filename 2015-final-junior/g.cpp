#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
string mos[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--.."
};
int main(){
    int n;
    string str;
    cin >> n >> str;
    vector<string> arr;
    string tmp;
    for (int i = 0; i < n; i++) {
        // printf("%d.\n",i);
        if (str[i] == '=') {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (str[j] == '=') cnt++;
                else break;
            }
            if (cnt == 3) tmp.push_back('-');
            if (cnt == 1) tmp.push_back('.');
            i += cnt - 1;
        }
        else {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (str[j] == '.') cnt++;
                else break;
            }
            if (cnt == 3 || cnt == 7) {
                arr.push_back(tmp);
                tmp.clear();
            }
            if (cnt == 7) arr.push_back("");
            i += cnt - 1;
        }
    }
    if (tmp.size()) arr.push_back(tmp);
    for (auto s: arr) {
        // puts(s.c_str());
        if (s == "") putchar(' ');
        else {
            for (int i = 0; i < 26; i++) {
                if (s == mos[i]) putchar('A' + i);
            }
        }
    }
    puts("");
}
