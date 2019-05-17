#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<long long> arr(n);
  for (long long &v : arr) {
    std::cin >> v;
    v = abs(v);
  }
  std::sort(arr.begin(), arr.end());

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int idx = std::upper_bound(arr.begin(), arr.end(), 2 * arr[i]) - arr.begin();
    ans += idx - 1 - i;
  }

  std::cout << ans << '\n';
  return 0;
}

