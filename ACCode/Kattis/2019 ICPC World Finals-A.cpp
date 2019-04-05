#include <bits/stdc++.h>

struct tile {int p, h, id;};
bool operator < (tile k1, tile k2) {
  if (k1.h == k2.h) return k1.id < k2.id;
  return k1.h < k2.h;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<tile> b(n), f(n);
  for (int i = 0; i < n; ++i) std::cin >> b[i].p;
  for (int i = 0; i < n; ++i) std::cin >> b[i].h;
  for (int i = 0; i < n; ++i) b[i].id = i;
  for (int i = 0; i < n; ++i) std::cin >> f[i].p;
  for (int i = 0; i < n; ++i) std::cin >> f[i].h;
  for (int i = 0; i < n; ++i) f[i].id = i;

  sort(b.begin(), b.end(), [&](tile k1, tile k2) {return k1.p < k2.p;});
  sort(f.begin(), f.end(), [&](tile k1, tile k2) {return k1.p < k2.p;});

  std::set<tile> b_s, f_s;
  std::vector<int> b_ans(n), f_ans(n);
  int b_cur = 0, f_cur = 0;

  for (int pos = 0; pos < n; ++pos) {
    if (b_s.empty()) {
      while (b_cur < n) {
        b_s.insert(b[b_cur]);
        ++b_cur;
        if (b[b_cur].p != b[b_cur - 1].p) break;
      }
    }
    if (f_s.empty()) {
      while (f_cur < n) {
        f_s.insert(f[f_cur]);
        ++f_cur;
        if (f[f_cur].p != f[f_cur - 1].p) break;
      }
    }
    
    if ((int)b_s.size() < (int)f_s.size()) {
      tile b_tmp = *b_s.begin();
      b_s.erase(b_s.begin());
      b_ans[pos] = b_tmp.id;
      auto it = f_s.lower_bound((tile){-1, b_tmp.h, -1});
      if (it == f_s.begin()) {
        std::cout << "impossible" << '\n';
        return 0;
      }
      tile f_tmp = *std::prev(it);
      f_ans[pos] = f_tmp.id;
      f_s.erase(std::prev(it));
    }
    else {
      tile f_tmp = *f_s.begin();
      f_s.erase(f_s.begin());
      f_ans[pos] = f_tmp.id;
      auto it = b_s.lower_bound((tile){-1, f_tmp.h + 1, -1});
      if (it == b_s.end()) {
        std::cout << "impossible" << '\n';
        return 0;
      }
      tile b_tmp = *it;
      b_ans[pos] = b_tmp.id;
      b_s.erase(it);
    }
  }

  for (auto &v : b_ans) std::cout << v + 1 << " ";
  std::cout << '\n';
  for (auto &v : f_ans) std::cout << v + 1 << " ";
  std::cout << '\n';
  return 0;
}
