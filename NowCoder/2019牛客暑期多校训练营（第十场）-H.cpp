#include <bits/stdc++.h>
const int maxn = 7;
std::map<std::vector<int>, std::string> map, spe;
void Init() {
  map[{1, 1, 2, 2, 2, 2}] = "n-hexane";
  map[{1, 1, 1, 1, 3, 3}] = "2,3-dimethylbutane";
  map[{1, 1, 1, 1, 2, 4}] = "2,2-dimethylbutane";
  spe[{1, 1, 3}] = "2-methylpentane";
  spe[{1, 2, 2}] = "3-methylpentane";
}
std::vector<int> g[maxn];
std::vector<int> vec, len;
void Dfs(int u, int p, int l) {
  bool f = true;
  for (int &v : g[u]) {
    if (v == p) continue;
    Dfs(v, u, l + 1);
    f = false;
  }
  if (f) len.push_back(l);
}
void Solve() {
  if (map.find(vec) == map.end()) {
    len.clear();
    for (int i = 1; i <= 6; ++i) if (g[i].size() == 3) Dfs(i, 0, 0);
    std::sort(len.begin(), len.end());
    std::cout << spe[len] << '\n';
  }
  else std::cout << map[vec] << '\n';
}
int main() {
  Init();
  int t;
  std::cin >> t;
  while (t--) {
    for (int i = 1; i <= 6; ++i) g[i].clear();
    for (int i = 1, u, v; i <= 5; ++i) {
      std::cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vec.clear();
    for (int i = 1; i <= 6; ++i) vec.push_back(g[i].size());
    std::sort(vec.begin(), vec.end());
    Solve();
  }
  return 0;
}
