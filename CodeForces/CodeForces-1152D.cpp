#include <bits/stdc++.h>
const int maxn = 2e3 + 5;
const int mod = 1e9 + 7;

int n;
int dp[maxn][maxn][2];

int Dfs(int l, int m, int f) {
  if (l == 2 * n && m == 0) return 0;
  if (m < 0 || l + m > 2 * n) return -f;
  if (dp[l][m][f] != -1) return dp[l][m][f];
  int ret = 0;
  if (f == 0) ret = std::max((Dfs(l + 1, m - 1, 1) + Dfs(l + 1, m + 1, 0) + 1) % mod, (Dfs(l + 1, m - 1, 0) + Dfs(l + 1, m + 1, 1) + 1) % mod);
  else ret = (Dfs(l + 1, m - 1, 0) + Dfs(l + 1, m + 1, 0)) % mod;
  dp[l][m][f] = ret;
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  std::cin >> n;

  std::cout << Dfs(0, 0, 0) << '\n';
  return 0;
}

