#include <bits/stdc++.h>
const int maxn = 3e2 + 5;

int t;
int n, m;
char map[maxn][maxn];
int dp[maxn][maxn][3];
int ans;

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", map[i] + 1);
    ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 0;
        if (map[i][j] == '.') {
          dp[i][j][0] = dp[i][j - 1][0] + 1;
          dp[i][j][1] = dp[i - 1][j][1] + 1;
          dp[i][j][2] = std::min(dp[i - 1][j - 1][2] + 1, std::min(dp[i][j][0], dp[i][j][1]));
          ans = std::max(ans, dp[i][j][2]);
        }
      }
    }
    printf("%d\n", ans * ans);
  }
  return 0;
}
