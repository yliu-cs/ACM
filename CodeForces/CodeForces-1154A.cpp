#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  std::vector<int> arr(4);
  for (auto &v : arr) std::cin >> v;
  std::sort(arr.begin(), arr.end());

  std::cout << arr[3] - arr[0] << ' ' << arr[3] - arr[1] << ' ' << arr[3] - arr[2] << '\n';
  return 0;
}

