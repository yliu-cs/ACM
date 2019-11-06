#include <bits/stdc++.h>

const int N = 55;
const int C = 26;

int k, n;
char s[N], t[N];
int cnt[C];
std::set<int> set[2][C];
std::vector<std::pair<int, int>> ans;

int Get(char x) {
  return (int)(x - 'a');
}

void Swap(int k1, int k2) {
  ans.push_back({k1, k2});
  char c1 = s[k1], c2 = t[k2];
  set[0][Get(c1)].erase(k1);
  set[0][Get(c2)].emplace(k1);
  set[1][Get(c2)].erase(k2);
  set[1][Get(c1)].emplace(k2);
  std::swap(s[k1], t[k2]);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> k;
  while (k--) {
    std::cin >> n >> (s + 1) >> (t + 1);
    for (int i = 0; i < C; ++i) {
      cnt[i] = 0;
      set[0][i].clear();
      set[1][i].clear();
    }
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      int x = Get(s[i]);
      ++cnt[x];
      set[0][x].emplace(i);
    }
    for (int i = 1; i <= n; ++i) {
      int x = Get(t[i]);
      ++cnt[x];
      set[1][x].emplace(i);
    }
    bool f = true;
    for (int i = 0; i < C; ++i) {
      if (cnt[i] & 1) {
        f = false;
        break;
      }
    }
    if (!f) {
      std::cout << "No" << '\n';
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      if (s[i] == t[i]) {
        set[0][Get(s[i])].erase(i);
        set[1][Get(t[i])].erase(i);
        continue;
      }
      int x = Get(s[i]);
      set[0][x].erase(i);
      if (!set[0][x].empty()) {
        int idx = *set[0][x].begin();
        Swap(idx, i);
      }
      else if (!set[1][x].empty()) {
        int idx = *set[1][x].begin();
        Swap(idx, idx);
        Swap(idx, i);
      }
      else {
        f = false;
        break;
      }
      set[1][Get(t[i])].erase(i);
    }
    if (!f) {
      std::cout << "No" << '\n';
    }
    else {
      std::cout << "Yes" << '\n';
      std::cout << ans.size() << '\n';
      for (auto &pr : ans) {
        std::cout << pr.first << ' ' << pr.second << '\n';
      }
    }
//    std::cout << "s: " << (s + 1) << '\n';
//    std::cout << "t: " << (t + 1) << '\n';
  }
  return 0;
}

