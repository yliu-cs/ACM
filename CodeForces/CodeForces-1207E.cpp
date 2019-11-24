#include <bits/stdc++.h>
 
int main() {
  std::cout << "? ";
  for (int i = 1; i <= 100; ++i) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  int x;
  std::cin >> x;
  std::cout << "? ";
  for (int i = 1; i <= 100; ++i) {
    std::cout << (i << 7) << ' ';
  }
  std::cout << std::endl;
  int y;
  std::cin >> y;
  int ans = 0;
  for (int i = 0; i < 14; ++i) {
    if (i < 7) {
      if ((1 << i) & y) {
        ans += (1 << i);
      }
    }
    else if ((1 << i) & x) {
      ans += (1 << i);
    }
  }
  std::cout << "! " << ans << '\n';
  return 0;
}
 
