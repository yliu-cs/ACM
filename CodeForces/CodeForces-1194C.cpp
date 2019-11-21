#include <bits/stdc++.h>

const int C = 26;

void Solve() {
  std::string s, t, p;
  std::cin >> s >> t >> p;
  std::vector<int> idx[C];
  for (int i = 0; i < (int)t.length(); ++i) {
    int x = t[i] - 'a';
    idx[x].push_back(i);
  }
  int cur = -1;
  for (int i = 0; i < (int)s.length(); ++i) {
    int x = s[i] - 'a';
    auto it = std::lower_bound(idx[x].begin(), idx[x].end(), cur);
    if (it == idx[x].end()) {
      std::cout << "NO" << '\n';
      return;
    }
    cur = (*it) + 1;
  }
  std::vector<int> cnt(C, 0);
  for (auto &c : t) {
    int x = c - 'a';
    ++cnt[x];
  }
  for (auto &c : s) {
    int x = c - 'a';
    --cnt[x];
  }
  for (auto &c : p) {
    int x = c - 'a';
    --cnt[x];
  }
  for (int i = 0; i < C; ++i) {
    if (cnt[i] > 0) {
      std::cout << "NO" << '\n';
      return;
    }
  }
  std::cout << "YES" << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}

