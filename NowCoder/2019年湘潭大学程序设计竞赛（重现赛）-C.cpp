#include <bits/stdc++.h>
 
int Get(int x) {
  return (x + 191) / 192;
}
 
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);
 
  int t; std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int l, r; std::cin >> l >> r;
    int cnt = Get(r) - Get(l - 1);
    int low = l, high = r;
    while (low % 192 != 1 && low <= r) ++low;
    while (high % 192 != 1 && high >= l) --high;
    std::cout << 1ll * (low + high) * cnt / 2 << '\n';
  }
 
  return 0;
}

