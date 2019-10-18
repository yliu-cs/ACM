// Author: Tony5t4rk Time: 2019-10-17 20:27:34 
#include <bits/stdc++.h>
const int D = 3;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> pt(n, std::vector<int>(D));
  for (auto &p : pt) for (auto &v : p) std::cin >> v;
  auto Dfs = [&](auto &Self, std::vector<int> ids, int k) {
    if (k == D) return ids[0];
    std::map<int, std::vector<int>> map;
    for (auto &id : ids) map[pt[id][k]].push_back(id);
    std::vector<int> buf;
    for (auto &pair : map) {
      int lst = Self(Self, pair.second, k + 1);
      if (lst != -1) buf.push_back(lst);
    }
    for (int i = 0; (i + 1) < buf.size(); i += 2) std::cout << buf[i] + 1 << ' ' << buf[i + 1] + 1 << '\n';
    return (buf.size() & 1 ? buf.back() : -1);
  };
  std::vector<int> id(n);
  std::iota(id.begin(), id.end(), 0);
  Dfs(Dfs, id, 0);
  return 0;
}
