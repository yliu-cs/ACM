#include <bits/stdc++.h>

const int INF = 1e9 + 5;

int main() {
  int n;
  scanf("%d", &n);
  int ans = INF;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) {
      ans = std::min(ans, i + i + n / i + n / i);
    }
  }
  printf("%d\n", ans);
  return 0;
}

