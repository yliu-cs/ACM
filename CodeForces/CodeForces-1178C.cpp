#include <bits/stdc++.h>
const int mod = 998244353;

long long Pow(long long x, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = (ret * x) % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}

int main() {
  long long w, h;
  std::cin >> w >> h;
  std::cout << 4ll * Pow(2, (w + h - 2 + mod) % mod) % mod << '\n';
  return 0;
}