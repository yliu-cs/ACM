#include <bits/stdc++.h>

int t;
long long m, n, k1, k2;

long long Pow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % n;
    x = x * x % n;
    y >>= 1;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    std::cin >> m >> n >> k1 >> k2;
    long long k = Pow(10 % n, k1 - 1) * (m % n) % n;
    for (int i = k1; i <= k2; ++i) {
      k *= 10;
      std::cout << k / n;
      k %= n;
    }
    std::cout << '\n';
  }
  return 0;
}
