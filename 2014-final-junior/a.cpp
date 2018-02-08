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
        int n;
        scanf("%d", &n);
        if (n == 0) putchar('0');
        string ans;
        if (n % 9) printf("%d", n % 9);
        for (int i = 0; i < n / 9; i++) printf("9");
        puts("");
    }
}
