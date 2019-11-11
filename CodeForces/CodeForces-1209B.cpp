#include <bits/stdc++.h>

const int T = 200;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::vector<int> cnt(T, 0);
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    if (s[i] == '1') {
      for (int j = 0; j < b; ++j) {
        ++cnt[j];
      }
    }
    int cur = s[i] == '1' ? 0 : 1;
    for (int k = 0; b + k * a < T; ++k) {
      for (int j = b + k * a; j < b + (k + 1) * a && j < T; ++j) {
        if (cur == 1) {
          ++cnt[j];
        }
      }
      cur ^= 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < T; ++i) {
    ans = std::max(ans, cnt[i]);
  }
  std::cout << ans << '\n';
  return 0;
}

