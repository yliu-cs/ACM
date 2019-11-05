#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, k; std::cin >> n >> k;
  std::vector<int> arr(n);
  for (int &v : arr) std::cin >> v;
  std::sort(arr.begin(), arr.end());
  std::cout << arr[k - 1] << '\n';

  return 0;
}

