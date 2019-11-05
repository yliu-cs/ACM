#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int t; std::cin >> t;
  for (int cas = 0; cas < t; ++cas) {
    int n; std::cin >> n;
    std::string str; std::cin >> str;

    int l = -1, r = -1;
    for (int i = 0; i < n; ++i)
      if (str[i] == '>') {
        l = i;
        break;
      }
    for (int i = n - 1; i > 0; --i) 
      if (str[i] == '<') {
        r = i;
        break;
      }

    std::cout << std::max(0, std::min(l, n - r - 1)) << '\n';
  }
  return 0;
}
