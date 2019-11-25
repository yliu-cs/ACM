#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    int n = (int)s.length(), x = 0, y = 0;
    std::vector<std::vector<int>> pos(n + 1, std::vector<int>(2, 0));
    std::vector<std::vector<int>> pre(n + 1, std::vector<int>(4, 0));
    pre[0][0] = pre[0][1] = pre[0][2] = pre[0][3] = 0;
    pos[0][0] = pos[0][1] = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'W') {
        ++y;
      }
      else if (s[i] == 'A') {
        --x;
      }
      else if (s[i] == 'S') {
        --y;
      }
      else if (s[i] == 'D') {
        ++x;
      }
      pos[i + 1][0] = x;
      pos[i + 1][1] = y;
      pre[i + 1][0] = std::min(pre[i][0], x);
      pre[i + 1][1] = std::max(pre[i][1], x);
      pre[i + 1][2] = std::min(pre[i][2], y);
      pre[i + 1][3] = std::max(pre[i][3], y);
    }
    std::vector<std::vector<int>> suf(n + 1, std::vector<int>(4, 0));
    suf[n][0] = pos[n][0];
    suf[n][1] = pos[n][0];
    suf[n][2] = pos[n][1];
    suf[n][3] = pos[n][1];
    for (int i = n - 1; i >= 0; --i) {
      suf[i][0] = std::min(suf[i + 1][0], pos[i][0]);
      suf[i][1] = std::max(suf[i + 1][1], pos[i][0]);
      suf[i][2] = std::min(suf[i + 1][2], pos[i][1]);
      suf[i][3] = std::max(suf[i + 1][3], pos[i][1]);
    }
    if (n == 1) {
      std::cout << 2 << '\n';
      continue;
    }
    long long ans = 1ll * (std::abs(pre[n][0] - pre[n][1]) + 1) * (std::abs(pre[n][2] - pre[n][3]) + 1);
    for (int i = 0; i < n; ++i) {
      int preleft = pre[i][0], preright = pre[i][1], pretop = pre[i][3], prebottom = pre[i][2];
      int sufleft = suf[i][0], sufright = suf[i][1], suftop = suf[i][3], sufbottom = suf[i][2];
      int left = 0, right = 0, top = 0, bottom = 0;
      left = std::min(sufleft, preleft);
      right = std::max(sufright, preright);
      top = std::max(suftop + 1, pretop);
      bottom = std::min(sufbottom + 1, prebottom);
      ans = std::min(ans, 1ll * (std::abs(left - right) + 1) * (std::abs(top - bottom) + 1));
      top = std::max(suftop - 1, pretop);
      bottom = std::min(sufbottom - 1, prebottom);
      ans = std::min(ans, 1ll * (std::abs(left - right) + 1) * (std::abs(top - bottom) + 1));
      top = std::max(suftop, pretop);
      bottom = std::min(sufbottom, prebottom);
      left = std::min(sufleft - 1, preleft);
      right = std::max(sufright - 1, preright);
      ans = std::min(ans, 1ll * (std::abs(left - right) + 1) * (std::abs(top - bottom) + 1));
      left = std::min(sufleft + 1, preleft);
      right = std::max(sufright + 1, preright);
      ans = std::min(ans, 1ll * (std::abs(left - right) + 1) * (std::abs(top - bottom) + 1));
    }
    std::cout << ans << '\n';
  }
  return 0;
}

