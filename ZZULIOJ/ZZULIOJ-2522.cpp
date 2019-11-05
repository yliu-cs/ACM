#include <bits/stdc++.h>

int main() {
  int n; scanf("%d", &n);
  std::map<int, int> cnt;
  int max = 0, ans;
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    ++cnt[x];
    if (cnt[x] > max) {
      max = cnt[x];
      ans = x;
    }
  }
  printf("%d\n", ans);
  return 0;
}

