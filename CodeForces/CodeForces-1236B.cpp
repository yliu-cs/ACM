// Author: Tony5t4rk Time: 2019-10-17 21:39:24 
#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
long long Pow(long long x, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = (ret * x) % MOD;
    x = (x * x) % MOD;
    n >>= 1;
  }
  return ret;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n, m;
  std::cin >> n >> m;
  std::cout << (Pow((Pow(2ll, m) - 1), n) + MOD) % MOD << '\n';
  return 0;
}
