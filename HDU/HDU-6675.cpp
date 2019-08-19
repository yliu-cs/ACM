#include <bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::set<int> > p(m);
    for (int i = 0; i < n; ++i) {
      std::string s1, s2;
      std::cin >> s1 >> s2;
      std::vector<int> pos[26];
      for (int j = 0; j < m; ++j) pos[s2[j] - 'a'].push_back(j);
      for (int j = 0; j < m; ++j) {
        if (i == 0) {
          for (int &v : pos[s1[j] - 'a']) p[j].insert(v);
        }
        else {
          std::vector<int> tmp;
          for (int &v : pos[s1[j] - 'a']) {
            if (p[j].find(v) != p[j].end()) tmp.push_back(v);
          }
          p[j].clear();
          for (int &v : tmp) p[j].insert(v);
        }
      }
    }
    std::vector<bool> vis(m, false);
    std::vector<int> ans;
    for (int i = 0; i < m; ++i) {
      std::set<int>::iterator it;
      for (it = p[i].begin(); it != p[i].end(); ++it) {
        if (!vis[*it]) break;
      }
      if (it != p[i].end()) {
        ans.push_back(*it);
        vis[*it] = true;
      }
    }
    if (ans.size() != m) std::cout << -1 << '\n';
    else {
      std::cout << ans[0] + 1;
      for (int i = 1; i < m; ++i) std::cout << ' ' << ans[i] + 1;
      std::cout << '\n';
    }
  }
  return 0;
}
