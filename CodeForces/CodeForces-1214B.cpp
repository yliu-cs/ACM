#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int b;
  std::cin >> b;
  int g;
  std::cin >> g;
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (i <= b && n - i <= g) {
      ++ans;
    }
  }
  std::cout << ans << '\n';
  return 0;
}

