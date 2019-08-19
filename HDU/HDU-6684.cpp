#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::string str;
    std::cin >> str;
    if (str[0] == 'z') {
      str[0] = 'b';
      std::cout << str << '\n';
      continue;
    }
    if (str[0] != 'y') {
      std::cout << str << '\n';
      continue;
    }
    int idx = 1;
    while (str[idx] == 'y' && idx < str.length()) ++idx;
    if (idx < str.length() && str[idx] == 'z') str[idx] = 'b';
    std::cout << str << '\n';
  }
  return 0;
}
