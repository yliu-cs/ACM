#include <bits/stdc++.h>
const long long mod = 1e9 + 7;

long long QuickPow(long long k, long long n) {
  if (n == 0) return 1;
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * k % mod;
    k = k * k % mod;
    n >>= 1;
  }
  return ans;
}

long long n, k;
std::vector<std::vector<int>> g;
std::vector<bool> vis;

int Dfs(int cur) {
  vis[cur] = true;
  int cnt = 1;
  for (auto &it : g[cur]) {
    if (vis[it]) continue;
    cnt += Dfs(it);
  }
  return cnt;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> n >> k;
  g.resize(n); vis.assign(n, false);
  for (int i = 1, u, v, x; i < n; ++i) {
    std::cin >> u >> v >> x;
    --u; --v;
    if (x == 0) {
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
  }

  long long ans = QuickPow(n, k);
  for (int i = 0; i < n; ++i) {
    if (!vis[i])
      ans = (ans - QuickPow(Dfs(i), k) + mod) % mod;
  }

  std::cout << ans << '\n';
  return 0;
}
