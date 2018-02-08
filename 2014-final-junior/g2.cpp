#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
typedef long long int LL;
#define x first
#define y second

int coin[8] = {1, 5, 10, 50, 100, 500, 1000, 10000000};

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<par> arr[8];
        for (int i = 0; i < 7; i++) {
            int x;
            scanf("%d", &x);
            arr[i].push_back({1, x});
        }
        int ans = 0, flag = 1;
        for (int i = 0; i < 7 && flag; i++) {
            int res = (n % coin[i + 1]) / coin[i];
            int tot = 0;
            for (auto pr: arr[i]) {
                // printf("coin = %d, %d - %d\n", coin[i], pr.x, pr.y);
                tot += pr.y;
            }
            if (res > tot) {
                flag = 0;
                break;
            }
            sort(arr[i].begin(), arr[i].end());
            while (res) {
                int mi = min(res, arr[i].back().y);
                ans += arr[i].back().x * mi;
                arr[i].back().y -= mi;
                res -= mi;
                if (arr[i].back().y == 0) arr[i].pop_back();
            }

            // to next
            while (true) {
                res = coin[i + 1] / coin[i];
                while (arr[i].size() && arr[i].back().y >= res) {
                    int cnt = arr[i].back().y / res;
                    arr[i].back().y -= cnt * res;
                    arr[i + 1].push_back({arr[i].back().x * res, cnt});
                    if (arr[i].back().y == 0) arr[i].pop_back();
                }
                int val = 0;
                while (res && arr[i].size()) {
                    int mi = min(res, arr[i].back().y);
                    val += arr[i].back().x * mi;
                    arr[i].back().y -= mi;
                    res -= mi;
                    if (arr[i].back().y == 0) arr[i].pop_back();
                }
                if (res) break;
                else arr[i + 1].push_back({val, 1});
            }
        }
        if (flag) printf("%d\n", ans);
        else puts("OAQ");

    }
}
