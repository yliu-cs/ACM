#include <bits/stdc++.h>
const int mod = (int)1e9 + 7;

bool Check(int &x) {
  if (x == 0) return false;
  int y = sqrt(x);
  return y * y != x;
}

int t, n;

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    if (!Check(n)) {
      printf("infty\n");
      continue;
    }
    else if (n % 4 != 0) {
      printf("0 0\n");
      continue;
    }

    int mul = n / 4;
    long long cnt = 0, ans = 0;
    for (int i = 1; i * i <= mul; ++i) {
      if (mul % i != 0) continue;
      ++cnt;
      if (i * i == mul) ans = (ans + 1ll * i * i % mod * i % mod * 2 % mod) % mod;
      else ans = (ans + 1ll * i * (mul / i) % mod * (i + mul / i) % mod) % mod;
    }

    printf("%lld %lld\n", cnt, ans);
  }
  return 0;
}
