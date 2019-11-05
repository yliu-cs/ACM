#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n; std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string str;
    for (int j = 0; j < 4; ++j) {
      std::cin >> str;
      if (str[2] == 'T') {
        std::cout << str[0] - 'A' + 1;
      }
    }
  }
  return 0;
}
