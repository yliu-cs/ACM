#include <bits/stdc++.h>
#include <bits/extc++.h>
const int inf = 1e9 + 5;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<int> arr(n);
  int ans = inf;
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
    if (i > 0) ans = std::min(ans, arr[i] / (i - 0));
    if (i < n - 1) ans = std::min(ans, arr[i] / (n - 1 - i));
  }

  std::cout << ans << '\n';

  return 0;
}

