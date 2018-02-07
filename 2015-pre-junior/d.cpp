#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    string type;
    string en, de;
    int n;
    string str;
    cin >> type >> en >> n >> str;
    for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++) {
        if (en[j] - 'a' == i) de.push_back(j + 'a');
    }
    if (type == "encrypt") {
        for (int i = 0; i < n; i++) {
            if (str[i] < 'a' || str[i] > 'z') continue;
            str[i] = en[str[i] - 'a'];
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (str[i] < 'a' || str[i] > 'z') continue;
            str[i] = de[str[i] - 'a'];
        }
    }
    puts(str.c_str());
}
