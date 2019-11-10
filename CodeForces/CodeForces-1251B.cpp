#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int cnt[2] = {0, 0};
    bool f = true;
    for (int i = 0; i < n; ++i) {
      std::string s;
      std::cin >> s;
      if ((int)s.length() & 1) {
        f = false;
      }
      for (auto &c : s) {
        ++cnt[c - '0'];
      }
    }
    if (f && cnt[0] & 1) {
      --n;
    }
    std::cout << n << '\n';
  }
  return 0;
}

