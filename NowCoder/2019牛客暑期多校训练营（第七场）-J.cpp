#include <bits/stdc++.h>

long long Reverse(long long x) {
  long long ret = 0;
  while (x) {
    ret = ret * 10 + x % 10;
    x /= 10;
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    printf("%lld\n", Reverse(Reverse(a) + Reverse(b)));
  }
  return 0;
}
