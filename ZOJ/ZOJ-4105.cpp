#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::set<char> set;
  set.insert('a'); set.insert('e');
  set.insert('i'); set.insert('o');
  set.insert('u'); set.insert('y');

  int t; std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    std::string str; std::cin >> str;
    std::cout << str[0];
    for (int i = 1; i < (int)str.size(); ++i) {
      if (set.find(str[i]) == set.end()) std::cout << str[i];
    }
    std::cout << '\n';
  }

  return 0;
}

