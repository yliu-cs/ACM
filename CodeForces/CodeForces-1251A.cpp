#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    std::set<char> set;
    int len = s.length();
    for (int l = 0, r; l < len; l = r + 1) {
      r = l;
      while (r + 1 < len && s[r + 1] == s[l]) {
        ++r;
      }
      if ((r - l + 1) & 1) {
        set.insert(s[l]);
      }
    }
    for (auto &c : set) {
      std::cout << c;
    }
    std::cout << '\n';
  }
  return 0;
}

