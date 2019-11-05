#include <bits/stdc++.h>
typedef long long ll;
const int maxn = 1e5 + 5;

char s[maxn];
int pre[maxn];
ll cnt[3];
ll ans;

int main() {
  s[0] = '#';
  scanf("%s", s + 1);
  int len = std::strlen(s + 1), zerocnt = 0;
  ++cnt[0];
  for (int i = 1; i <= len; ++i) {
    pre[i] = pre[i - 1] + (s[i] - '0');
    if (s[i] == '0') ++zerocnt;
    if (s[i] == '0' && s[i - 1] == '0') ans += cnt[pre[i] % 3];
    if (i > 1) ++cnt[pre[i - 1] % 3];
  }
  ans += zerocnt;
  printf("%lld\n", ans);
  return 0;
}