// Author: Tony5t4rk Time: 2019-08-20 22:35:33 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s;
  std::cin >> s;
  std::reverse(s.begin(), s.end());
  bool ok = false;
  for (int i = 0; i < s.length(); ++i) {
    if (i < s.length() - 1 && s[i] == '1') ok = true;
  }
  int ans = s.length() / 2 + (ok && (s.length() % 2 != 0));
  std::cout << ans << '\n';
  return 0;
}
