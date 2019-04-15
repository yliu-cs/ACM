#include <bits/stdc++.h>
const int maxn = 3e2 + 5;

int n, m;
int matrix[maxn][maxn];
int dp[maxn];
int ans;

bool Check(int r1, int r2) {
  for (int i = 1; i <= m; ++i) {
    if (matrix[r1][i] <= matrix[r2][i]) return false;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &matrix[i][j]);
    }
  }

  for (int i = n; i >= 1; --i) {
    dp[i] = 1;
    for (int j = i + 1; j <= n; ++j) {
      if (Check(i, j)) dp[i] = std::max(dp[i], dp[j] + 1);
    }
    ans = std::max(ans, dp[i]);
  }

  printf("%d\n", n - ans);
  return 0;
}

