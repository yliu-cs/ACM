#include <bits/stdc++.h>

const int N = 1e3 + 5;

int t, n, a[N], ans;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
      std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    std::reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
      if (a[i] >= i) {
        ans = i;
      }
      else {
        break;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}

