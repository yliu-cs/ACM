#include <bits/stdc++.h>
const int maxn = 1e2 + 5;

int t;
int n, k, m;
int cnt[2];
char s[maxn];
long long max;

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d%d", &n, &k, &m);
    scanf("%s", s);
    max = 0;
    cnt[0] = cnt[1] = 0;
    for (int i = 0; i < n; ++i) {
      ++cnt[s[i] - '0'];
      max = std::max(max, (long long)(cnt[1] - std::max(0, cnt[0] - k)));
    }
    printf("%lld\n", std::max(0ll, std::max(max, 1ll * (m - 1) * (cnt[1] - std::max(0, cnt[0] - k)) + max)));
  }
  return 0;
}