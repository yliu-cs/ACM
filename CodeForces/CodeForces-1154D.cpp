#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, init_b, init_a; std::cin >> n >> init_b >> init_a;
  int a = init_a, b = init_b;
  std::vector<int> s(n);
  for (auto &v : s) std::cin >> v;

  for (int i = 0; i < n; ++i) {
    if (b == 0 && a == 0) {
      std::cout << i << '\n';
      return 0;
    }
    if (s[i] == 0) {
      if (a) --a;
      else --b;
    }
    else {
      if (b) {
        if (a < init_a) {
          --b;
          ++a;
        else --a;
      }
      else --a;
    }
  }
  std::cout << n << '\n';
  return 0;
}

