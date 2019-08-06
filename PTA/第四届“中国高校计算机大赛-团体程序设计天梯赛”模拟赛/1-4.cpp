#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n; std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string name; int a, b;
    std::cin >> name >> a >> b;
    if (a >= 15 && a <= 20 && b >= 50 && b <= 70) continue;
    std::cout << name << '\n';
  }
  return 0;
}
