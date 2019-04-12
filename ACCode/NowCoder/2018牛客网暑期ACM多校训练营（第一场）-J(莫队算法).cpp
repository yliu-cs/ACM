#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

template <typename t>
inline bool read(t &ret) {
  char c; int sgn;
  if (c = getchar(), c == EOF) return false;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return true;
}

int n, m;
int block;
int arr[maxn];
struct query {int l, r, id;};
query q[maxn];
int cur;
int cnt[maxn];
int ans[maxn];

void Del(int x) {
  cur -= (--cnt[arr[x]] == 0);
}

void Add(int x) {
  cur += (++cnt[arr[x]] == 1);
}

int main() {
  while (read(n) && read(m)) {
    memset(cnt, 0, sizeof(cnt));
    block = (int)sqrt(n);

    for (int i = 1; i <= n; ++i) read(arr[i]);
    for (int i = 1; i <= m; ++i) {
      read(q[i].l); read(q[i].r);
      q[i].id = i;
    }
    std::sort(q + 1, q + m + 1, [&](query k1, query k2) {
      return (k1.l / block) == (k2.l / block) ? k1.r < k2.r : k1.l < k2.l;
    });

    int l = 0, r = n + 1; cur = 0;
    for (int i = 1; i <= m; ++i) {
      int ql = q[i].l, qr = q[i].r;
      while (l < ql) Add(++l);
      while (l > ql) Del(l--);
      while (r < qr) Del(r++);
      while (r > qr) Add(--r);
      ans[q[i].id] = cur;
    }

    for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  }
  return 0;
}

