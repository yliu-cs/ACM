#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n; std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string str; std::cin >> str;
    std::sort(str.begin(), str.end());
    bool flag = true;
    for (int i = 1; i < (int)str.size(); ++i) {
      if (str[i] != str[i - 1] + 1) flag = false;
    }
    if (flag) std::cout << "Yes" << '\n';
    else std::cout << "No" << '\n';
  }
  return 0;
}
