#include <bits/stdc++.h>

long long l, r;
long long ans;
int len;

int main() {
  scanf("%lld%lld", &l, &r);
  ans = l;
  len = log2(r) + 1;
  for (int i = 0; i < len; ++i) {
    if (((1ll << i) & l) == 0) {
      long long temp = ans + (1ll << (long long)i);
      if (temp > r) break;
      ans = temp;
    }
  }
  printf("%lld\n", ans);
  return 0;
}

