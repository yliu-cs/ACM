#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int t;
    scanf("%d", &t);
    for (int Case = 1, n, m; Case <= t; ++Case) {
        scanf("%d%d", &n, &m);
        vector<bool> vis(16, false);
        vector<int> cnt(16, 0);
        int Cnt = 0, Ans = 0;
        for (int i = 1, x; i <= m; ++i) {
            scanf("%d", &x);
            x %= 100;
            string time, result;
            cin >> time >> result;
            if (result == "AC") {
                if (!vis[x]) {
                    vis[x] = true;
                    Cnt++;
                    cnt[x] += ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + (time[3] - '0') * 10 + (time[4] - '0');
                    Ans += cnt[x];
                }
            }
            else {
                cnt[x] += 20;
            }
        }
        printf("%d %d\n", Cnt, Ans);
    }
    return 0;
}

