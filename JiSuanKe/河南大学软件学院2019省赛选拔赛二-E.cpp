#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  std::string s; std::cin >> s;
  std::string arr[5];
  for (int i = 0; i < 5; ++i) {
    std::cin >> arr[i];
    if (arr[i][0] == s[0] || arr[i][1] == s[1]) {
      std::cout << "YES" << '\n';
      std::cout << arr[i] << '\n';
      return 0;
    }
  }
  
  std::cout << "NO" << '\n';
  return 0;
}
