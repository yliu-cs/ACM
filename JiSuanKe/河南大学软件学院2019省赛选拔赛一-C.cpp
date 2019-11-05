#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int t; std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int n; std::cin >> n;
    std::vector<long long> s(n);
    for (auto &v : s) std::cin >> v;
    sort(s.begin(), s.end(), [&](long long k1, long long k2) {return k1 > k2;});
    std::cout << ((s[1] + s[2]) ^ s[0]) << '\n';
  }
  return 0;
}
