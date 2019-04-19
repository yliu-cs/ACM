#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);
  
  int n; std::cin >> n;
  std::vector<int> arr(n);
  for (auto &v : arr) std::cin >> v;
  std::sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  int size = (int)arr.size();
  if (size > 3) {
    std::cout << -1 << '\n';
    return 0;
  }
  if (size == 3) {
    if (abs(arr[2] - arr[1]) == abs(arr[1] - arr[0])) {
      std::cout << arr[1] - arr[0] << '\n';
      return 0;
    }
    std::cout << -1 << '\n';
    return 0;
  }
  if (size == 2) {
    if ((arr[1] - arr[0]) & 1) {
      std::cout << arr[1] - arr[0] << '\n';
      return 0;
    }
    std::cout << (arr[1] - arr[0]) / 2 << '\n';
    return 0;
  }
  if (size == 1) {
    std::cout << 0 << '\n';
    return 0;
  }
  return 0;
}

