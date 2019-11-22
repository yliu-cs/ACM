#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::map<std::string, int> cnt;
  std::string s[3];
  int ans = 2;
  for (int i = 0; i < 3; ++i) {
    std::cin >> s[i];
    ++cnt[s[i]];
  }
  for (int i = 0; i < 3; ++i) {
    ans = std::min(ans, 3 - cnt[s[i]]);
  }
  for (int i = 0; i < 3; ++i) {
    if (s[i][0] != '9' && s[i][0] != '8') {
      std::string buf1 = s[i], buf2 = s[i];
      ++buf1[0];
      buf2[0] += 2;
      ans = std::min(ans, (cnt[buf1] == 0) + (cnt[buf2] == 0));
    }
    if (s[i][0] != '1' && s[i][0] != '9') {
      std::string buf1 = s[i], buf2 = s[i];
      --buf1[0];
      ++buf2[0];
      ans = std::min(ans, (cnt[buf1] == 0) + (cnt[buf2] == 0));
    }
    if (s[i][0] != '1' && s[i][0] != '2') {
      std::string buf1 = s[i], buf2 = s[i];
      --buf1[0];
      buf2[0] -= 2;
      ans = std::min(ans, (cnt[buf1] == 0) + (cnt[buf2] == 0));
    }
  }
  std::cout << ans << '\n';
  return 0;
}

