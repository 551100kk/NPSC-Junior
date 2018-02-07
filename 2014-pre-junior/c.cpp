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
        int bin = 1;
        int n;
        scanf("%d", &n);
        while (bin < n) bin *= 2;
        printf("1 %d\n", max(bin - n, 1));
    }
}
