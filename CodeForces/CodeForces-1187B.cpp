#include <bits/stdc++.h>

const int C = 26;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::vector<std::vector<int>> idx(C);
  for (int i = 0; i < n; ++i) {
    idx[s[i] - 'a'].push_back(i + 1);
  }
  int q;
  std::cin >> q;
  while (q--) {
    std::string t;
    std::cin >> t;
    int m = (int)t.length();
    std::vector<int> cnt(C, 0);
    for (int i = 0; i < m; ++i) {
      ++cnt[t[i] - 'a'];
    }
    int ans = 0;
    for (int i = 0; i < C; ++i) {
      if (cnt[i] == 0) {
        continue;
      }
      ans = std::max(ans, idx[i][cnt[i] - 1]);
    }
    std::cout << ans << '\n';
  }
  return 0;
}

