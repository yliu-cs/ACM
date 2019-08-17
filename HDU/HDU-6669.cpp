#include <bits/stdc++.h>
struct interval { int l, r; };
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i] >> b[i];
    std::vector<interval> seg;
    int x = 0;
    while (x < n) {
      int y = x + 1;
      int l = a[x], r = b[x];
      while (a[y] <= r && b[y] >= l && y < n) {
        if (a[y] >= l) l = a[y];
        if (b[y] <= r) r = b[y];
        ++y;
      }
      seg.push_back((interval){l, r});
      x = y;
    }
    int sz = seg.size(), last = seg[1].l > seg[0].r ? seg[0].r : seg[0].l, pos;
    long long cnt = 0;
    for (int i = 1; i < sz; ++i) {
      if (seg[i].l > seg[i - 1].r) {
        if (i == sz - 1) pos = seg[i].l;
        if ((seg[i].l - last) % 2 == 0) pos = seg[i].l;
        else {
          if (seg[i + 1].l > seg[i].r && seg[i].r > seg[i].l) pos = seg[i].l + 1;
          else pos = seg[i].l;
        }
      }
      else if (seg[i].r < seg[i - 1].l) {
        if (i == sz - 1) pos = seg[i].r;
        if ((last - seg[i].r) % 2 == 0) pos = seg[i].r;
        else {
          if (seg[i + 1].r < seg[i].l && seg[i].l < seg[i].r) pos = seg[i].r - 1;
          else pos = seg[i].r;
        }
      }
      cnt += (std::abs(pos - last) + 1) / 2;
      last = pos;
    }
    std::cout << cnt << '\n';
  }
  return 0;
}
