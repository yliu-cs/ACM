#include <bits/stdc++.h>
const int maxn = 5e4 + 5;

int n, m, k;
int block;
long long arr[maxn];
long long sum[maxn];
struct query {int l, r, id;};
query q[maxn];
long long cur;
long long ans[maxn];

void Del(int x) {
  --sum[arr[x]];
  cur -= 2 * sum[arr[x]] + 1;
}

void Add(int x) {
  ++sum[arr[x]];
  cur += 2 * sum[arr[x]] - 1;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  block = (int)sqrt(n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &arr[i]);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].id = i;
  }
  std::sort(q + 1, q + m + 1, [&](query k1, query k2) {
    return (k1.l / block) == (k2.l / block) ? k1.l < k2.l : k1.r < k2.r;
  });

  int l = 1, r = 0;
  for (int i = 1; i <= m; ++i) {
    int ql = q[i].l, qr = q[i].r;
    while (l < ql) Del(l++);
    while (l > ql) Add(--l);
    while (r < qr) Add(++r);
    while (r > qr) Del(r--);
    ans[q[i].id] = cur;
  }

  for (int i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
  return 0;
}

