#include <bits/stdc++.h>

const int N = 1e5 + 5;

int n, m, ans;
std::map<int, int> g[N];
std::set<int> set;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    std::cin >> u >> v;
    g[u][v] = g[v][u] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    set.insert(i);
  }
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (set.count(i)) {
      std::queue<int> que;
      int cur = 0;
      que.push(i);
      while (!que.empty()) {
        int u = que.front();
        que.pop();
        std::vector<int> buf;
        for (auto &v : set) {
          if (g[u].count(v) == 0) {
            ++cur;
            que.push(v);
            buf.emplace_back(v);
          }
        }
        for (auto &v : buf) {
          set.erase(v);
        }
      }
      ++ans;
    }
  }
  std::cout << ans - 1 << '\n';
  return 0;
}

