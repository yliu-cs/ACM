// Author: Tony5t4rk Time: 2019-10-21 20:12:13 
#include <bits/stdc++.h>
const int C = 2;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::string s, t;
  std::cin >> n >> s >> t;
  std::queue<int> buf[2];
  std::vector<std::pair<int, int>> ans;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      if (s[i] == 'a') {
        if (!buf[0].empty()) {
          ans.push_back({buf[0].front(), i});
          buf[0].pop();
        }
        else buf[0].push(i);
      }
      else {
        if (!buf[1].empty()) {
          ans.push_back({buf[1].front(), i});
          buf[1].pop();
        }
        else buf[1].push(i);
      }
    }
  }
  if (buf[0].size() != buf[1].size()) {
    std::cout << -1 << '\n';
    return 0;
  }
  while (!buf[0].empty() || !buf[1].empty()) {
    ans.push_back({buf[0].front(), buf[0].front()});
    ans.push_back({buf[0].front(), buf[1].front()});
    buf[0].pop(); buf[1].pop();
  }
  std::cout << ans.size() << '\n';
  for (auto &pair : ans) std::cout << pair.first + 1 << ' ' << pair.second + 1 << '\n';
  return 0;
}

