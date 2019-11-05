#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e2 + 5;

int main(int argc, char *argv[]) {
    int t;
    scanf("%d", &t);
    for (int Case = 1, n, m; Case <= t; ++Case) {
        scanf("%d", &n);
        vector<int> a(n + 1), pre(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            pre[i] = pre[i - 1] ^ a[i];
        }
        int res[maxn][maxn];
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                res[i][j] = pre[i - 1] ^ pre[j];
            }
        }
        scanf("%d", &m);
        for (int i = 1, query; i <= m; ++i) {
            scanf("%d", &query);
            int ans = INF, len = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = i; j <= n; ++j) {
                    if (ans > abs(res[i][j] - query)) {
                        ans = abs(res[i][j] - query);
                        len = j - i + 1;
                    }
                    else if (ans == abs(res[i][j] - query)) {
                        len = max(len, j - i + 1);
                    }
                }
            }
            printf("%d\n", len);
        }
        putchar('\n');
    }
    return 0;
}

