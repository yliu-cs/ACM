#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    bool f = true;
    for (int j = i - 1, k = 0; j > 0 && k < x; --j, ++k) {
      if (a[j] < a[i]) {
        f = false;
      }
    }
    for (int j = i + 1, k = 0; j < n && k < y; ++j, ++k) {
      if (a[j] < a[i]) {
        f = false;
      }
    }
    if (f) {
      std::cout << i + 1 << '\n';
      return 0;
    }
  }
  return 0;
}

