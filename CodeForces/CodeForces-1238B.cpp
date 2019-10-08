#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, r;
    std::cin >> n >> r;
    std::vector<int> x(n);
    for (auto &v : x) std::cin >> v;
    std::sort(x.begin(), x.end(), [&](int k1, int k2) { return k1 > k2; });
    x.erase(std::unique(x.begin(), x.end()), x.end());
    int offset = 0, ans = 0;
    for (auto &v : x) {
      if (v <= offset) break;
      ++ans;
      offset += r;
    }
    std::cout << ans << '\n';
  }
  return 0;
}
