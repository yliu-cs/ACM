// Author: Tony5t4rk Time: 2019-10-02 14:59:59 
#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::map<char, std::string> map;
  map['Y'] = "QQQ"; map['V'] = "QQW"; map['G'] = "QQE"; map['C'] = "WWW"; map['X'] = "QWW";
  map['Z'] = "WWE"; map['T'] = "EEE"; map['F'] = "QEE"; map['D'] = "WEE"; map['B'] = "QWE";
  for (auto &pair : map) std::sort(pair.second.begin(), pair.second.end());
  std::string str;
  std::cin >> str;
  int len = str.length();
  str.erase(std::unique(str.begin(), str.end()), str.end());
  if (str.length() == 1) {
    std::cout << len + 3 << '\n';
    return 0;
  }
  std::vector<std::vector<int>> dp(str.length(), std::vector<int>(6, inf));
  auto Transfer = [](std::string pre, std::string cur) -> int {
    if (pre == cur) return 0;
    else if (pre[1] == cur[0] && pre[2] == cur[1]) return 1;
    else if (pre[2] == cur[0]) return 2;
    return 3;
  };
  for (int i = 0; i < 6; ++i) dp[0][i] = 3;
  int ans = inf;
  for (int i = 1; i < str.length(); ++i) {
    std::string pre = map[str[i - 1]], cur = map[str[i]];
    int curidx = 0;
    do {
      int preidx = 0;
      std::sort(pre.begin(), pre.end());
      do {
        dp[i][curidx] = std::min(dp[i][curidx], dp[i - 1][preidx++] + Transfer(pre, cur));
      } while (std::next_permutation(pre.begin(), pre.end()));
      if (i == str.length() - 1) ans = std::min(ans, dp[i][curidx]);
      ++curidx;
    } while (std::next_permutation(cur.begin(), cur.end()));
  }
  std::cout << len + ans << '\n';
  return 0;
}
