#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  int d;
  std::cin >> d;
  int e;
  std::cin >> e;
  int ans = n;
  for (int i = 0; ; ++i) {
    if (i * d > n) {
      break;
    }
    int j = (n - i * d) / (5 * e);
    ans = std::min(ans, n - i * d - 5 * j * e);
  }
  std::cout << ans << '\n';
  return 0;
}

