#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef long long int LL;
#define x first
#define y second

set<string> ac[30];

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int id, team, time;
        string prob, ver;
        cin >> id >> team >> time >> prob >> ver;
        if (ver != "AC" || time >= 180) continue;
        if (ac[team].find(prob) != ac[team].end()) continue;
        ac[team].insert(prob);
        printf("Send balloon of %s to team %d at time %d.\n", prob.c_str(), team, time);
    }
    puts("Go get snacks.");
}
