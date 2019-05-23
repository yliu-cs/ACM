#include <bits/stdc++.h>
typedef long long ll;
const int maxn = 1e5 + 5;
const ll inf = 1e17;

int t;
ll n, m;
ll a[maxn];
ll d[maxn];
ll l, r;
ll ans;

bool Check(ll x) {
  for (int i = 1; i <= n; ++i) d[i] = 0;
  ll la = m;
  for (int i = 1; i <= n; ++i) {
    if (la > 0) {
      --la;
      d[i] += a[i];
    }
    else break;
    if (x > d[i]) {
      ll diff = x - d[i];
      ll cnt = (diff + a[i] - 1) / a[i];
      if (2ll * cnt > la) break;
      else {
        d[i] += cnt * a[i];
        d[i + 1] += cnt * a[i + 1];
        if (2ll * cnt == la) break;
        la -= 2ll * cnt;
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    if (d[i] < x) return false;
  return true;
}

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%lld%lld", &n, &m);
    l = r = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      r = std::max(r, a[i] * m);
    }
    a[n + 1] = 0;

    ans = 0;
    while (l <= r) {
      ll m = (l + r) / 2;
      if (Check(m)) {
        ans = m;
        l = m + 1;
      }
      else r = m - 1;
    }

    printf("%lld\n", ans);
  }
  return 0;
}

