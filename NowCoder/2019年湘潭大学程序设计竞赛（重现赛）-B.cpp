#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int t; std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int n; std::cin >> n;
    int ans = 0;
    while (n > 1) {
      if (n % 10 == 0) ++ans;
      else {
        ans += 10 - (n % 10) + 1;
        n += 10 - (n % 10);
      }
      n /= 10;
    }
    std::cout << ans << '\n';
  }
  return 0;
}

