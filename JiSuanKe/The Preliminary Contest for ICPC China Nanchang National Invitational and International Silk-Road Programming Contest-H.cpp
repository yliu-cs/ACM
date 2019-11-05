#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1e9 + 7;

ll Pow(ll x, ll n) {
  ll ret = 1;
  while (n) {
    if (n & 1) ret = (ret * x) % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  ll n; std::cin >> n;
  if (n == 1) std::cout << 1 << '\n';
  else std::cout << 4ll * Pow(3, n - 2) % mod << '\n';
  return 0;
}

