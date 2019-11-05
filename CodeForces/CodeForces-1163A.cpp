#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m; std::cin >> n >> m;

  if (m == 0) {
    std::cout << 1 << '\n';
    return 0;
  }

  if (n & 1) {
    if (m < n / 2) std::cout << m << '\n';
    else if (m <= n / 2 + 1) std::cout << n / 2 << '\n';
    else std::cout << n / 2 - (m - (n / 2 + 1)) << '\n';
  }
  else {
    if (m < n / 2) std::cout << m << '\n';
    else if (m <= n / 2) std::cout << n / 2 << '\n';
    else std::cout << n / 2 - (m - (n / 2)) << '\n';
  }

  return 0;
}

