#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int a, b; std::cin >> a >> b;
  int mul = a * b;
  int flag = false;
  while (mul) {
    if (mul % 10 != 0) flag = true;
    if (flag) std::cout << mul % 10;
    mul /= 10;
  }
  return 0;
}
