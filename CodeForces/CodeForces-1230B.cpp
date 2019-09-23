#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(15);
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  if (k == 0) {
    std::cout << str << '\n';
    return 0;
  }
  if (n == 1 && k >= 1) {
    std::cout << 0 << '\n';
    return 0;
  }
  if (str[0] != '1') {
    str[0] = '1';
    --k;
  }
  for (int i = 1; i < str.length() && k > 0; ++i) {
    if (str[i] != '0') {
      str[i] = '0';
      --k;
    }
  }
  std::cout << str << '\n';
  return 0;
}
