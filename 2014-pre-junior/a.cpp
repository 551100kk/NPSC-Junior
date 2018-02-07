#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second
int main(){
    double AB, H, BB, HBP, TB, SF;
    int n;
    scanf("%d", &n);
    while (n--) {
        cin >> AB >> H >> BB >> HBP >> TB >> SF;
        double top = AB * (H + BB + HBP) + TB * (AB + BB + SF + HBP);
        double down = AB * (AB + BB + SF + HBP);
        printf("%.3f\n", top / down);
    }
}
