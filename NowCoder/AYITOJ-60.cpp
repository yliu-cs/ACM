#include <bits/stdc++.h>
struct node { int v, r; };

int main() {
  int t;
  std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<int> b(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    std::vector<node> cnt((int)b.size());
    for (int i = 0; i < n; ++i) {
      int num = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
      ++cnt[num].v;
      if (num != (int)b.size() - 1) cnt[num].r = num + 1;
      else cnt[num].r = -1;
    }
    std::vector<int> ans;
    int low = 0;
    while (m > 0) {
      int idx = low, la = -1;
      if (idx == -1) break;
      ++m;
      while (idx != -1 && m > 0) {
        if (cnt[idx].v > 0) {
          ans.push_back(b[idx]);
          --cnt[idx].v;
          --m;
        }
        if (cnt[idx].v == 0) {
          if (la == -1) low = cnt[idx].r;
          else cnt[la].r = cnt[idx].r;
        }
        la = idx;
        idx = cnt[idx].r;
      }
    }
    if (m > 0) {
      std::cout << -1 << '\n';
      continue;
    }
    std::reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); ++i) std::cout << ans[i] << ' ';
    for (int i = low; i != -1; i = cnt[i].r) {
      while (cnt[i].v > 0) {
        std::cout << b[i] << ' ';
        --cnt[i].v;
      }
    }
    std::cout << '\n';
  }
  return 0;
}