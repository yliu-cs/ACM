#include <bits/stdc++.h>

void Find(int n, unsigned long long k) {
  if (n == 1) {
    printf("%llu\n", k);
  }
  else if ((unsigned long long)std::pow(2, n - 1) <= k) {
    printf("1");
    Find(n - 1, (unsigned long long)std::pow(2, n) - k - 1);
  }
  else {
    printf("0");
    Find(n - 1, k);
  }
}

int main() {
  unsigned long long n, k;
  scanf("%llu%llu", &n, &k);
  Find(n, k);
  return 0;
}

