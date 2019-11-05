#include <bits/stdc++.h>
const int mod = 20180520;

long long Pow(long long x, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = (ret * x) % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}

long long n;

int main() {
  scanf("%lld", &n);
  printf("%lld\n", Pow(2ll, n));
  return 0;
}

