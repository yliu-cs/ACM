#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  freopen("portals.in", "r", stdin);

  int t; std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int n; std::cin >> n;
    std::string str; std::cin >> str;
    int s_pos, e_pos;
    for (int i = 0; i < n; ++i) {
      if (str[i] == 's') s_pos = i;
      else if (str[i] == 'e') e_pos = i;
    }
    if (s_pos > e_pos) std::swap(s_pos, e_pos);

    int sl = -1, sr = -1, el = -1, er = -1;
    for (int i = s_pos - 1; i >= 0; --i) {
      if (str[i] == 'o') {
        sl = i;
        break;
      }
      else if (str[i] == '#') break;
    }
    for (int i = e_pos + 1; i < n; ++i) {
      if (str[i] == 'o') {
        er = i;
        break;
      }
      else if (str[i] == '#') break;
    }
    for (int i = s_pos + 1; i < e_pos; ++i) {
      if (str[i] == 'o') {
        sr = i;
        break;
      }
      else if (str[i] == '#') {
        sr = -2;
        break;
      }
    }
    for (int i = e_pos - 1; i > s_pos; --i) {
      if (str[i] == 'o') {
        el = i;
        break;
      }
      else if (str[i] == '#') {
        el = -2;
        break;
      }
    }

    auto GetLeft = [&](int pos) -> bool {
      if (pos == 0) return false;
      return str[pos - 1] == 'o';
    };
    auto GetRight = [&](int pos) -> bool {
      if (pos == n - 1) return false;
      return str[pos + 1] == 'o';
    };

    if (((GetLeft(s_pos) || GetRight(s_pos)) && (GetLeft(e_pos) || GetRight(e_pos))) || abs(s_pos - e_pos) == 1) {
      std::cout << -1 << '\n';
      continue;
    }

    const int inf = 2e5 + 5;
    int ans1 = 0, ans2 = 0;
    if (GetLeft(s_pos) || GetRight(s_pos)) ans1 = inf;
    if (sl != -1) ans1++;
    if (sr >= -1) ans1++;

    if (GetLeft(e_pos) || GetRight(e_pos)) ans2 = inf;
    if (er != -1) ans2++;
    if (el >= -1) ans2++;

    std::cout << std::min(ans1, ans2) << '\n';
  }
  return 0;
}
