#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    int n;
    scanf("%d", &n);
    if (n == 0) puts("1");
    else if (n == 1) puts("0");
    else {
        if (n % 2) putchar('4');
        for (int i = 0; i < n / 2; i++) putchar('8');
        puts("");
    }
}
