#include <bits/stdc++.h>

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int t, n, h[N];
long long cnt, ans;
bool f;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &h[i]);
    }
    f = true;
    for (int i = 1; i <= n; ++i) {
      if (h[i] > n - 1 || h[i] < h[i - 1] || (i != 1 && h[i] == 0) || (i == 1 && h[i] != 0)) {
        f = false;
        break;
      }
    }
    if (!f) {
      std::cout << 0 << '\n';
      continue;
    }
    cnt = 0;
    ans = 1;
    for (int i = 2; i <= n; ++i) {
      if (h[i] > h[i - 1]) {
        ans = (ans * 2) % MOD;
        cnt += h[i] - h[i - 1] - 1;
      }
      else if (h[i] == h[i - 1]) {
        ans = (ans * cnt) % MOD;
        --cnt;
      }
      if (cnt < 0) {
        f = false;
        break;
      }
    }
    if (f) {
      printf("%lld\n", ans);
    }
    else {
      printf("0\n");
    }
  }
  return 0;
}

