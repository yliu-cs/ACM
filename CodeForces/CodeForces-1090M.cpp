#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, k; std::cin >> n >> k;
  int len = 1, last = -1, ans = 1;
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    if (last == -1) {
      last = x;
      continue;
    }
    if (x == last) len = 1;
    else ++len;
    ans = std::max(ans, len);
    last = x;
  }

  std::cout << ans << '\n';
  return 0;
}

