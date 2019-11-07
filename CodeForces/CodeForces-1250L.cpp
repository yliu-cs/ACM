#include <bits/stdc++.h>

int t, a, b, c;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &a, &b, &c);
    if (c < a) {
      std::swap(a, c);
    }
    int l = std::min({a, b, c}), r = std::max({a, b, c}), ans;
    while (l <= r) {
      int m = (l + r) / 2;
      if (std::max(a, b - std::max(0, std::min(m - a, b)) + c - m) <= m) {
        ans = m;
        r = m - 1;
      }
      else {
        l = m + 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

