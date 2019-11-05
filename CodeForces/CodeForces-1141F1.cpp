#include <bits/stdc++.h>

struct seg {int l, r;};
bool operator < (seg k1, seg k2) {
  if (k1.r == k2.r) return k1.l < k2.l;
  return k1.r < k2.r;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);

  int n; std::cin >> n;
  std::vector<int> a(n);
  for (auto &it : a) std::cin >> it;

  std::map<int, std::set<seg>> mp;
  for (int l = 0; l < n; ++l) {
    int sum = 0;
    for (int r = l; r < n; ++r) {
      sum += a[r];
      mp[sum].insert((seg){l + 1, r + 1});
    }
  }

  std::vector<seg> ans, temp;
  for (auto &i : mp) {
    temp.clear();
    for (auto &j : i.second) {
      if (j.l > (temp.empty() ? 0 : temp.back().r)) temp.emplace_back(j);
    }
    if (temp.size() > ans.size()) std::swap(ans, temp);
  }

  std::cout << ans.size() << '\n';
  for (auto &it : ans) std::cout << it.l << " " << it.r << '\n';
  return 0;
}
