#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
  }
  std::vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    int max = 0;
    for (int j = 0; j < 5; ++j) {
      int buf = 0;
      for (int k = 0; k < n; ++k) {
        if (s[k][i] == (char)(j + 'A')) {
          buf += a[i];
        }
      }
      max = std::max(max, buf);
    }
    ans += max;
  }
  std::cout << ans << '\n';
  return 0;
}

