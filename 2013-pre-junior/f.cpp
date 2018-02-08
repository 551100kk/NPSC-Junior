#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int m, d, hh, mm, ss;
        int time1 = 0;
        int time2 = 0;
        scanf("%d-%d %d:%d:%d", &m, &d, &hh, &mm, &ss);
        int x = 1, y = 1;
        for (int i = 1;; i++) {
            if (m == x && d == y) {
                time1 = i;
                break;
            }
            y++;
            if (y > days[x]) x++, y = 1;
        }
        time1 = time1 * 86400 + hh * 3600 + mm * 60 + ss;

        scanf(", %d-%d %d:%d:%d", &m, &d, &hh, &mm, &ss);
        x = 1, y = 1;
        for (int i = 1;; i++) {
            if (m == x && d == y) {
                time2 = i;
                break;
            }
            y++;
            if (y > days[x]) x++, y = 1;
        }
        time2 = time2 * 86400 + hh * 3600 + mm * 60 + ss;
        int dur = time2 - time1;
        if (dur < 0) putchar('-'), dur *= -1;
        printf("%d %02d:%02d:%02d\n", dur / 86400, dur / 3600 % 24, dur / 60 % 60, dur % 60);
    }
}
