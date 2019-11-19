#include <bits/stdc++.h>

int main() {
//  std::ios::sync_with_stdio(false);
//  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    if (m < n || n == 2) {
      std::cout << -1 << '\n';
      continue;
    }
    long long ans = 0;
    std::vector<std::pair<int, int>> record;
    for (int i = 0; i < n; ++i) {
      record.push_back({i, (i + 1) % n});
      ans += a[i] + a[(i + 1) % n];
    }
    std::cout << ans << '\n';
    for (int i = 0; i < (int)record.size(); ++i) {
      std::cout << record[i].first + 1 << ' ' << record[i].second + 1 << '\n';
    }
  }
  return 0;
}

