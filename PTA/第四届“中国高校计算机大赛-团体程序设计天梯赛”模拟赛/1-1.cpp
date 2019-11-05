#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n; std::cin >> n;
  std::set<int> find, vis;
  for (int i = 0; i < n; ++i) {
    int k; std::cin >> k;
    for (int j = 0; j < k; ++j) {
      int x; std::cin >> x;
      if (k > 1) find.insert(x);
    }
  }
  int m; std::cin >> m;
  bool flag = false, first = true;
  for (int i = 0; i < m; ++i) {
    int q; std::cin >> q;
    if (find.find(q) == find.end() && vis.find(q) == vis.end()) {
      if (!first) std::cout << " ";
      if (q < 10) std::cout << "0000";
      else if (q < 100) std::cout << "000";
      else if (q < 1000) std::cout << "00";
      else if (q < 10000) std::cout << "0";
      std::cout << q;
      if (first) first = false;
      vis.insert(q);
      flag = true;
    }
  }
  if (!flag) std::cout << "No one is handsome";
  std::cout << '\n';
  return 0;
}
