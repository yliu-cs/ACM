#include <bits/stdc++.h>

std::vector<int> d = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

int F(int x) {
  if (x == 0) return d[0];
  int ret = 0;
  while (x) {
    ret += d[x % 10];
    x /= 10;
  }
  return ret;
}

int main() {
  int t; scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    int n, k; scanf("%d%d", &n, &k);
    int cur = n;
    while (k--) {
      cur = F(cur);
      if (cur == 0) break;
    }
    if (k > 0) {
      if (k & 1) printf("1\n");
      else printf("0\n");
      continue;
    }
    printf("%d\n", cur);
  }
  return 0;
}

