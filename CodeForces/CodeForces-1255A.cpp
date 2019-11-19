#include <bits/stdc++.h>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a > b) {
      std::swap(a, b);
    }
    int d[3] = {5, 2, 1}, ans = 0;
    for (int i = 0; i < 3; ++i) {
      int diff = b - a, buf = diff / d[i];
      ans += buf;
      a += buf * d[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}

