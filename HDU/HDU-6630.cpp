#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 998244353;

long long data[maxn];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  data[0] = 1;
  for (int i = 1; i <= 4; ++i) data[i] = i;
  for (int i = 5; i < maxn; ++i) data[i] = (data[i - 2] + data[i - 3] + data[i - 4]) % mod;
  int t;
  std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int n, x, y;
    std::cin >> n >> x >> y;
    if (x > y) std::swap(x, y);
    if (x != 1 && y != n && std::abs(x - y) == 1) {
      std::cout << 0 << '\n';
      continue;
    }
    int l, r;
    if (x == 1) l = x;
    else l = x + 1;
    if (y == n) r = y;
    else r = y - 1;
    int len = std::max(r - l - 1, 0);
    std::cout << data[len] << '\n';
  }
  return 0;
}
