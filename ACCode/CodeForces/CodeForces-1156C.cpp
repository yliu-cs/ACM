#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, z; std::cin >> n >> z;
  std::vector<int> arr(n);
  for (int &v : arr) std::cin >> v;
  std::sort(arr.begin(), arr.end());

  int l = 0, r = n / 2;
  int ans = 0;
  for (int i = 0; i < n / 2; ++i) {
    while (arr[r] < arr[l] + z && r < n) ++r;
    if (arr[r] < arr[l] + z || r >= n) break;
    ++l; ++r;
    ++ans;
  }

  std::cout << ans << '\n';
  return 0;
}

