#include <bits/stdc++.h>

int GetSite(long long x) {
  int ret = 0;
  while (x) {
    ++ret;
    x /= 10;
  }
  return ret;
}

int main() {
  long long n, p;
  scanf("%lld%lld", &n, &p);
  if (n < GetSite(p)) {
    printf("T_T\n");
    return 0;
  }
  printf("%lld", p);
  for (int i = 0; i < (n - GetSite(p)); ++i) printf("0");
  printf("\n");
  return 0;
}
