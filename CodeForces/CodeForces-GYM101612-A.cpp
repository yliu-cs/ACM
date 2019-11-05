#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  freopen("auxiliary.in", "r", stdin);
  freopen("auxiliary.out", "w", stdout);

  int n; std::cin >> n;

  if (n % 3 == 0) std::cout << 7ll * n / 3;
  else if (n % 3 == 1) std::cout << 7ll * (n / 3 - 1) + 4;
  else if (n % 3 == 2) std::cout << 7ll * (n / 3) + 1;

  return 0;
}

