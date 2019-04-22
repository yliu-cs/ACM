#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::string str; std::cin >> str;
  for (int i = 1; i < n; ++i) {
    if (str[i] >= str[i - 1]) continue;
    std::cout << "YES\n" << i << ' ' << i + 1 << '\n';
    return 0;
  }
  std::cout << "NO\n";
  return 0;
}

