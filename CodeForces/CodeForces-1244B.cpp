// Author: Tony5t4rk Time: 2019-10-13 17:12:48 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::string str;
    std::cin >> str;
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
      if (str[i] == '1') {
        if (l == -1) l = i + 1;
        r = i + 1;
      }
    }
    if (l == -1) std::cout << n << '\n';
    else if (r == -1) std::cout << std::max(l * 2, (n - l + 1) * 2) << '\n';
    else std::cout << std::max({l * 2, (n - l + 1) * 2, r * 2, (n - r + 1) * 2}) << '\n';
  }
  return 0;
}
