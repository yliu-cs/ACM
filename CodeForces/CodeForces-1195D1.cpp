#include <bits/stdc++.h>

long long Pow(long long x, long long n, long long m) {
  long long ret = 1;
  while (n) {
    if (n & 1) {
      ret = (ret * x) % m;
    }
    x = (x * x) % m;
    n >>= 1;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  const int MOD = 998244353;
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    long long x = a[i], site = 0;
    while (x) {
      ans = (ans + (1ll * (x % 10) * Pow(10, 2 * site, MOD) % MOD) * n % MOD) % MOD;
      x /= 10;
      ++site;
    }
    x = a[i];
    site = 0;
    while (x) {
      ans = (ans + (1ll * (x % 10) * Pow(10, 2 * site + 1, MOD) % MOD) * n % MOD) % MOD;
      x /= 10;
      ++site;
    }
  }
  std::cout << ans << '\n';
  return 0;
}

