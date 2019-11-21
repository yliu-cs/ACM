#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    if (k % 3 == 0) {
      n %= (k + 1);
      if (n % 3 != 0 || n == k) {
        std::cout << "Alice" << '\n';
      }
      else {
        std::cout << "Bob" << '\n';
      }
    }
    else {
      if (n % 3 == 0) {
        std::cout << "Bob" << '\n';
      }
      else {
        std::cout << "Alice" << '\n';
      }
    }
  }
  return 0;
}

