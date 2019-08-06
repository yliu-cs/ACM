#include <bits/stdc++.h>
const int maxn = 1e6 + 5;

int n;
char str[maxn];
long long dp[maxn][4];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  scanf("%s", str + 1);
  n = strlen(str + 1);

  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (dp[i - 1][j] == 0) continue;
      if (j < 3) dp[i][j + 1] += dp[i - 1][j];
      dp[i][j] += dp[i - 1][j];
      for (int k = i - 1; k >= 1 && i - k <= j; --k) {
        if (str[k] == str[i]) {
          dp[i][j] -= dp[k - 1][j - (i - k)];
          break;
        }
      }
    }
  }

  std::cout << dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] << '\n';
  return 0;
}
