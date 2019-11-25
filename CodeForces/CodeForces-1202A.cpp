#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::string x, y;
    std::cin >> x >> y;
    std::reverse(x.begin(), x.end());
    std::reverse(y.begin(), y.end());
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < (int)y.length(); ++i) {
      if (y[i] == '1') {
        idx1 = i;
        break;
      }
    }
    for (int i = idx1; i < (int)x.length(); ++i) {
      if (x[i] == '1') {
        idx2 = i;
        break;
      }
    }
    std::cout << std::abs(idx1 - idx2) << '\n';
  }
  return 0;
}

