#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int v, e, k; std::cin >> v >> e >> k;
  std::vector<int> col(v);
  std::vector<std::pair<int, int>> edge;
  for (int i = 0, u, v; i < e; ++i) {
    std::cin >> u >> v;
    --u; --v;
    edge.push_back({u, v});
  }

  int n; std::cin >> n;
  std::set<int> cnt;
  for (int i = 0; i < n; ++i) {
    cnt.clear();
    for (int j = 0; j < v; ++j) {
      std::cin >> col[j];
      cnt.insert(col[j]);
    }
    if ((int)cnt.size() != k) {
      std::cout << "No";
      if (i != n - 1) std::cout << '\n';
      continue;
    }
    bool flag = true;
    for (auto &e : edge) {
      if (col[e.first] == col[e.second]) {
        flag = false;
        break;
      }
    }
    if (flag) std::cout << "Yes";
    else std::cout << "No";
    if (i != n - 1) std::cout << '\n';
  }
  return 0;
}
