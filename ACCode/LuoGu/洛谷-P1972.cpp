#include <bits/stdc++.h>
const int maxn = 5e5 + 5;

int n, m;
int block;
int arr[maxn];
struct query {int l, r, id;};
query q[maxn];
int cnt[maxn << 1];
int cur;
int ans[maxn];

inline void Del(int x) {
  cur -= (--cnt[arr[x]] == 0);
}

inline void Add(int x) {
  cur += (++cnt[arr[x]] == 1);
}

int main() {
  scanf("%d", &n);
  block = (int)sqrt(n);
  for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].id = i;
  }
  std::sort(q + 1, q + m + 1, [&](query k1, query k2) {
    return (k1.l / block) == (k2.l / block) ? (((k1.l / block) & 1) ? k1.r < k2.r : k1.r > k2.r) : k1.l < k2.l;
  });

  int l = 0, r = 0;
  for (int i = 1; i <= m; ++i) {
    int ql = q[i].l, qr = q[i].r;
    while (r < qr) Add(++r);
    while (r > qr) Del(r--);
    while (l > ql) Add(--l);
    while (l < ql) Del(l++);
    ans[q[i].id] = cur;
  }

  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}

