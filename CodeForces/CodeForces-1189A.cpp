#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::vector<std::vector<int>> pref(n, std::vector<int>(2, 0));
  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      pref[i][0] = pref[i - 1][0];
      pref[i][1] = pref[i - 1][1];
    }
    ++pref[i][s[i] - '0'];
  }
  if (pref[n - 1][0] != pref[n - 1][1]) {
    std::cout << 1 << '\n';
    std::cout << s << '\n';
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    std::vector<int> pre(2, 0);
    pre[0] = pref[i - 1][0];
    pre[1] = pref[i - 1][1];
    std::vector<int> suf(2, 0);
    suf[0] = pref[n - 1][0] - pref[i - 1][0];
    suf[1] = pref[n - 1][1] - pref[i - 1][1];
    if (pre[0] != pre[1] && suf[0] != suf[1]) {
      std::cout << 2 << '\n';
      for (int j = 0; j < i; ++j) {
        std::cout << s[j];
      }
      std::cout << ' ';
      for (int j = i; j < n; ++j) {
        std::cout << s[j];
      }
      std::cout << '\n';
      return 0;
    }
  }
  return 0;
}

