#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  std::map<int, int> map;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    ++map[a[i]];
  }
  std::sort(a.begin(), a.end());
  a.erase(std::unique(a.begin(), a.end()), a.end());
  int ans = 0, last = (n + 1) / 2;
  for (int c = 2; c > 0; --c) {
    for (int i = 0; i < (int)a.size(); ++i) {
      while (map[a[i]] >= c && last > 0) {
        ans += c;
        map[a[i]] -= c;
        --last;
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}

