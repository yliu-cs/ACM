#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> deg(n, 0);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;
    ++deg[u];
    ++deg[v];
  }
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 2) {
      std::cout << "NO" << '\n';
      return 0;
    }
  }
  std::cout << "YES" << '\n';
  return 0;
}

