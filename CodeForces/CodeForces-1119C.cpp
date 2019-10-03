// Author: Tony5t4rk Time: 2019-10-03 13:39:12 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (auto &r : a) for (auto &v : r) std::cin >> v;
  std::vector<std::vector<int>> b(n, std::vector<int>(m));
  for (auto &r : b) for (auto &v : r) std::cin >> v;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != b[i][j]) ++cnt;
    }
    if (cnt & 1) {
      std::cout << "No" << '\n';
      return 0;
    }
  }
  for (int j = 0; j < m; ++j) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i][j] != b[i][j]) ++cnt;
    }
    if (cnt & 1) {
      std::cout << "No" << '\n';
      return 0;
    }
  }
  std::cout << "Yes" << '\n';
  return 0;
}
