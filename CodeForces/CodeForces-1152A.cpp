#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m; std::cin >> n >> m;
  std::vector<int> cnt(4);
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    if (x & 1) ++cnt[0];
    else ++cnt[1];
  }
  for (int i = 0, x; i < m; ++i) {
    std::cin >> x;
    if (x & 1) ++cnt[2];
    else ++cnt[3];
  }
  std::cout << std::min(cnt[0], cnt[3]) + std::min(cnt[1], cnt[2]) << '\n';
  return 0;
}

