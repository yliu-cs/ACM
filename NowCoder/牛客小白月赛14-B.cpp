#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const long long mod = 998244353;

long long Pow(long long x, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = (ret * x) % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}

long long fac[maxn], facinv[maxn];

void GetFacInv() {
  fac[0] = 0; fac[1] = 1;
  for (int i = 2; i < maxn; ++i) fac[i] = (fac[i - 1] * i) % mod;
  facinv[maxn - 1] = Pow(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; --i) facinv[i] = (facinv[i + 1] * (i + 1)) % mod;
}

long long Lucas(long long n, long long m) {
  long long ret = 1;
  while (n && m) {
    long long a = n % mod, b = m % mod;
    if (a < b) return 0;
    ret = ret * fac[a] % mod * facinv[b] % mod * facinv[a - b] % mod;
    n /= mod, m /= mod;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  GetFacInv();
  long long n, k, p; std::cin >> n >> k >> p;
  long long _p = 1ll - p;
  while (_p < 0) _p += mod;

  long long ans = 0;
  for (int i = k; i <= n; ++i) {
    ans = (ans + Lucas(n, i) * Pow(p, i) % mod * Pow(_p, n - i) % mod) % mod;
  }

  std::cout << ans << '\n';
  return 0;
}

