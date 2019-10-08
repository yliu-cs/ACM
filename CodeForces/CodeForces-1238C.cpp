#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int h, n;
    std::cin >> h >> n;
    std::vector<int> p(n);
    for (auto &v : p) std::cin >> v;
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
      if (i == n - 1) {
        if (p[i] + 1 > 2) ++cnt;
        continue;
      }
      if (p[i + 1] != p[i] - 1) ++cnt;
      else ++i;
    }
    std::cout << cnt << '\n';
  }
  return 0;
}
