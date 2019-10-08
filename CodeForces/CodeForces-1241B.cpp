// Author: Tony5t4rk Time: 2019-10-08 12:35:42 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int q;
  std::cin >> q;
  while (q--) {
    std::string s, t;
    std::cin >> s >> t;
    std::set<char> set;
    for (auto &c : s) set.insert(c);
    bool flag = false;
    for (auto &c : t) if (set.find(c) != set.end()) flag = true;
    if (flag) std::cout << "YES" << '\n';
    else std::cout << "NO" << '\n';
  }
  return 0;
}
