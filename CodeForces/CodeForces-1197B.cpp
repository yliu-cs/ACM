#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int max = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (a[i] > a[max]) {
      max = i;
    }
  }
  bool f = true;
  for (int i = max - 1; i >= 0; --i) {
    if (a[i] > a[i + 1]) {
      f = false;
    }
  }
  for (int i = max + 1; i < n; ++i) {
    if (a[i] > a[i - 1]) {
      f = false;
    }
  }
  if (f) {
    std::cout << "YES" << '\n';
  }
  else {
    std::cout << "NO" << '\n';
  }
  return 0;
}

