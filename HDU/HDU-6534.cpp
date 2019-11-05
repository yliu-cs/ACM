#include <bits/stdc++.h>
#define lowbit(x) (x&(-x))
const int maxn = 3e4 + 5;

int n, m, k;
int a[maxn];
struct data { int v, l, r; };
data arr[maxn];
int ans[maxn];
int hash[maxn];
int sz;

int tree[maxn];

void Modify(int idx, int x) {
  while (idx <= sz) {
    tree[idx] += x;
    idx += lowbit(idx);
  }
}

int GetRank(int x) {
  int ret = 0;
  while (x > 0) {
    ret += tree[x];
    x -= lowbit(x);
  }
  return ret;
}

struct query { int l, r, id; };
query q[maxn];
int block;
int l, r;
int cur;

void Add(int idx) {
  cur += GetRank(arr[idx].r) - GetRank(arr[idx].l);
  Modify(arr[idx].v, 1);
}

void Del(int idx) {
  Modify(arr[idx].v, -1);
  cur -= GetRank(arr[idx].r) - GetRank(arr[idx].l);
}

void MoCap() {
  block = sqrt(n);
  std::sort(q + 1, q + m + 1, [&](query k1, query k2) {
    return (k1.l / block) == (k2.l / block) ? k1.r < k2.r : k1.l < k2.l;
  });
  l = q[1].l;
  r = l - 1;
  for (int i = 1; i <= m; ++i) {
    while (l < q[i].l) Del(l++);
    while (l > q[i].l) Add(--l);
    while (r < q[i].r) Add(++r);
    while (r > q[i].r) Del(r--);
    ans[q[i].id] = cur;
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    hash[i] = a[i];
  }
  std::sort(hash + 1, hash + n + 1);
  sz = std::unique(hash + 1, hash + n + 1) - hash - 1;
  for (int i = 1; i <= n; ++i) {
    arr[i].v = std::lower_bound(hash + 1, hash + sz + 1, a[i]) - hash;
    arr[i].l = std::lower_bound(hash + 1, hash + sz + 1, a[i] - k) - hash - 1;
    arr[i].r = std::upper_bound(hash + 1, hash + sz + 1, a[i] + k) - hash - 1;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].id = i;
  }
  MoCap();
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}