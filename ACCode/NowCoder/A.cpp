#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  int sum = 0;
  for (int &v : arr) {
    std::cin >> v;
    sum += v;
  }
  int cnt = arr[0];
  std::vector<int> idx;
  for (int i = 1; i < n; ++i) {
    if (arr[i] * 2 <= arr[0]) {
      idx.push_back(i + 1);
      cnt += arr[i];
    }
  }
  if (cnt * 2 <= sum) {
    std::cout << 0 << '\n';
    return 0;
  }
  std::cout << idx.size() + 1 << '\n';
  std::cout << 1 << ' ';
  for (int &v : idx) std::cout << v << ' ';
  std::cout << '\n';
  return 0;
}