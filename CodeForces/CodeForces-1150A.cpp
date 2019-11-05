#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m, r; std::cin >> n >> m >> r;
  std::vector<int> s(n), b(m);
  for (auto &v : s) std::cin >> v;
  for (auto &v : b) std::cin >> v;

  std::sort(s.begin(), s.end());
  std::sort(b.begin(), b.end(), [&](int k1, int k2) {return k1 > k2;});
  if (s[0] < b[0]) {
    int cnt = r / s[0];
    r -= cnt * s[0];
    r += cnt * b[0];
  }

  std::cout << r << '\n';

  return 0;
}

