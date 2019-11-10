#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    int n = s.length();
    std::vector<int> next(n);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        next[i] = i;
      }
      else if (i == 0) {
        next[i] = -1;
      }
      else {
        next[i] = next[i - 1];
      }
    }
    int ans = 0;
    for (int r = 0; r < n; ++r) {
      int sum = 0;
      for (int l = r; l >= 0 && r - l < 20; --l) {
        if (s[l] == '0') {
          continue;
        }
        sum += 1 << (r - l);
        if (sum <= r - (l == 0 ? -1 : next[l - 1])) {
          ++ans;
        }
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}

