// Author: Tony5t4rk Time: 2019-10-20 18:23:07 
#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n, m;
  std::cin >> n >> m;
  if (n > m) std::swap(n, m);
  std::vector<long long> dpm(m + 1, 0);
  dpm[1] = 2; dpm[2] = 4;
  for (int i = 3; i <= m; ++i) dpm[i] = (dpm[i - 2] + dpm[i - 1]) % MOD;
  long long ans = dpm[m];
  --n;
  std::vector<long long> dpn(n + 1, 0);
  long long pref = 0;
  if (n >= 1) {
    dpn[1] = 2;
    pref = (pref + dpn[1]) % MOD;
  }
  if (n >= 2) {
    dpn[2] = 2;
    pref = (pref + dpn[2]) % MOD;
  }
  for (int i = 3; i <= n; ++i) {
    dpn[i] = (dpn[i - 2] + dpn[i - 1]) % MOD;
    pref = (pref + dpn[i]) % MOD;
  }
  ans = (ans + pref) % MOD;
  std::cout << ans << '\n';
  return 0;
}
