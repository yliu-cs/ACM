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
  std::vector<int> cnt(11, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    ++cnt[log10(a[i])];
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int l = 0; l < 11; ++l) {
      long long x = a[i], site = 0;
      while (x) {
        if (site <= l) {
          ans = (ans + (1ll * (x % 10) * Pow(10, 2 * site, MOD) % MOD) * cnt[l] % MOD) % MOD;
        }
        else {
          ans = (ans + (1ll * (x % 10) * Pow(10, (l + 1) * 2 - 1 + (site - l), MOD) % MOD) * cnt[l] % MOD) % MOD;
        }
        x /= 10;
        ++site;
      }
      x = a[i];
      site = 0;
      while (x) {
        if (site <= l) {
          ans = (ans + (1ll * (x % 10) * Pow(10, 2 * site + 1, MOD) % MOD) * cnt[l] % MOD) % MOD;
        }
        else {
          ans = (ans + (1ll * (x % 10) * Pow(10, (l + 1) * 2 - 1 + (site - l), MOD) % MOD) * cnt[l] % MOD) % MOD;
        }
        x /= 10;
        ++site;
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}

