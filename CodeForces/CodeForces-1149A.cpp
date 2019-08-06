#include <bits/stdc++.h>
const int maxn = 4e5 + 5;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<int> arr(n), cnt(3);
  for (int &v : arr) {
    std::cin >> v;
    ++cnt[v];
  }

  if (cnt[2]) {
    std::cout << 2 << ' ';
    --cnt[2];
  }
  if (cnt[1] & 1) {
    for (int i = 0; i < cnt[1]; ++i) std::cout << 1 << ' ';
    for (int i = 0; i < cnt[2]; ++i) std::cout << 2 << ' ';
    std::cout << '\n';
  }
  else {
    for (int i = 0; i < cnt[1] - 1; ++i) std::cout << 1 << ' ';
    for (int i = 0; i < cnt[2]; ++i) std::cout << 2 << ' ';
    if (cnt[1] != 0) std::cout << 1;
    std::cout << '\n';
  }

  return 0;
}
