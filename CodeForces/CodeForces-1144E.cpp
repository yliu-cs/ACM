#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::string str1, str2; std::cin >> str1 >> str2;
  reverse(str1.begin(), str1.end());
  reverse(str2.begin(), str2.end());

  if (str2[0] > 'a') --str2[0];
  else {
    int pos = 0;
    while (str2[pos] == 'a') ++pos;
    for (int i = 0; i < pos; ++i) str2[i] = 'z';
    --str2[pos];
  }

  std::vector<int> s(n, 0), t(n, 0);
  for (int i = 0; i < n; ++i) {
    s[i] = str1[i] - 'a';
    t[i] = str2[i] - 'a';
  }

  std::vector<int> diff(n, 0);
  for (int i = 0; i < n; ++i) {
    if (t[i] >= s[i]) diff[i] = t[i] - s[i];
    else {
      diff[i] = t[i] + 26 - s[i];
      --t[i + 1];
    }
  }

  reverse(diff.begin(), diff.end());
  bool last = false;
  for (int i = 0; i < n; ++i) {
    if (last) diff[i] += 26;
    last = false;
    if (diff[i] & 1) last = true;
    diff[i] /= 2;
  }
  if (last) ++diff.back();

  reverse(diff.begin(), diff.end());
  std::vector<int> ans(n, 0);
  for (int i = 0; i < n; ++i) {
    ans[i] += s[i] + diff[i];
    if (ans[i] >= 26) {
      ans[i] -= 26;
      ++ans[i + 1];
    }
  }

  reverse(ans.begin(), ans.end());
  for (auto &v : ans) std::cout << (char)('a' + v);
  std::cout << '\n';

  return 0;
}
