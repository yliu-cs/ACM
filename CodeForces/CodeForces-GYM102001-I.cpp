#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  int n; std::cin >> n;
  std::vector<std::string> arr(n);
  for (auto &str : arr) std::cin >> str;
  std::reverse(arr.begin(), arr.end());
  bool flag = true;
  for (auto &it : arr) {
    if (it == "LIE") flag = !flag;
  }
  if (flag) std::cout << "TRUTH" << '\n';
  else std::cout << "LIE" << '\n';
  return 0;
}
