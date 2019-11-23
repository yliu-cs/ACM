#include <bits/stdc++.h>

const int N = 1e5 + 5;

int t, n, m, a[N];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      if (r - l + 1 > 40) {
        printf("yes\n");
        continue;
      }
      std::vector<int> buf;
      for (int j = l; j <= r; ++j) {
        buf.emplace_back(a[j]);
      }
      std::sort(buf.begin(), buf.end());
      bool f = false;
      for (int j = 0; j < (int)buf.size() - 2; ++j) {
        if (buf[j] + buf[j + 1] > buf[j + 2]) {
          f = true;
          break;
        }
      }
      if (f) {
        printf("yes\n");
      }
      else {
        printf("no\n");
      }
    }
  }
  return 0;
}

