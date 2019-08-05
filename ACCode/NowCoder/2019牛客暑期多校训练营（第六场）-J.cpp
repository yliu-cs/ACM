#include <bits/stdc++.h>
const int maxn = 1e3 + 5;
 
int t;
int n, m;
long long ans;
long long c[maxn][maxn];
long long d[maxn];
long long get[maxn];
long long pref[maxn][maxn];
long long max[maxn][maxn];
 
int main() {
  std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        std::cin >> c[i][j];
    for (int j = 1; j <= m; ++j) std::cin >> d[j];
    memset(get, 0, sizeof(get));
    for (int j = 1; j <= m; ++j) {
      get[j] = get[j - 1] + d[j];
      for (int i = 1; i <= n; ++i) get[j] -= c[i][j];
    }
    memset(pref, 0, sizeof(pref));
    memset(max, 0, sizeof(max));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) pref[i][j] = pref[i][j - 1] - c[i][j];
      max[i][m] = pref[i][m];
      for (int j = m - 1; j >= 1; --j) max[i][j] = std::max(pref[i][j], max[i][j + 1]);
    }
    ans = 0;
    for (int idx = 0; idx <= m; ++idx) {
      long long res = get[idx];
      if (idx != m) {
        std::vector<long long> vec;
        for (int i = 1; i <= n; ++i) {
          long long c = max[i][idx + 1] - pref[i][idx];
          if (c > 0) vec.emplace_back(c);
        }
        if ((int)vec.size() == n) {
          std::sort(vec.begin(), vec.end(), [&](const long long &k1, const long long &k2) { return k1 > k2; });
          for (int i = 0; i < n - 1; ++i) res += vec[i];
        }
        else {
          for (long long &v : vec) res += v;
        }
      }
      ans = std::max(ans, res);
    }
    std::cout << "Case #" << cas << ": " << ans << '\n';
  }
  return 0;
}