#include <bits/stdc++.h>
const int maxn = 5e5 + 5;
const int maxm = 5e5 + 5;
int n, m;
int a[maxn];
int sz, arr[maxn + maxm];
int Get(int x) {
  return std::lower_bound(arr + 1, arr + sz + 1, x) - arr;
}
struct Node {
  int ls, rs, cnt;
  Node() { ls = rs = cnt = 0; }
};
int tot;
int rt[maxn];
Node tree[maxn * 40];
int tmp[2][20], cnt[2];
void TreeModify(int &o, int l, int r, int idx, int v) {
  if (!o) o = ++tot;
  tree[o].cnt += v;
  if (l == r) return;
  int mid = (l + r) / 2;
  if (idx <= mid) TreeModify(tree[o].ls, l, mid, idx, v);
  else TreeModify(tree[o].rs, mid + 1, r, idx, v);
}
void Modify(int idx, int var) {
  int v = Get(a[idx]);
  for (int i = idx; i <= n; i += i & (-i)) TreeModify(rt[i], 1, sz, v, var);
}
int TreeQuery(int l, int r, int k) {
  if (l == r) return l;
  int mid = (l + r) / 2, sum = 0;
  for (int i = 1; i <= cnt[1]; ++i) sum += tree[tree[tmp[1][i]].ls].cnt;
  for (int i = 1; i <= cnt[0]; ++i) sum -= tree[tree[tmp[0][i]].ls].cnt;
  if (k <= sum) {
    for (int i = 1; i <= cnt[1]; ++i) tmp[1][i] = tree[tmp[1][i]].ls;
    for (int i = 1; i <= cnt[0]; ++i) tmp[0][i] = tree[tmp[0][i]].ls;
    return TreeQuery(l, mid, k);
  }
  else {
    for (int i = 1; i <= cnt[1]; ++i) tmp[1][i] = tree[tmp[1][i]].rs;
    for (int i = 1; i <= cnt[0]; ++i) tmp[0][i] = tree[tmp[0][i]].rs;
    return TreeQuery(mid + 1, r, k - sum);
  }
}
int Query(int l, int r, int k) {
  memset(tmp, 0, sizeof(tmp));
  cnt[0] = cnt[1] = 0;
  for (int i = r; i; i -= i & (-i)) tmp[1][++cnt[1]] = rt[i];
  for (int i = l - 1; i; i -= i & (-i)) tmp[0][++cnt[0]] = rt[i];
  return TreeQuery(1, sz, k);
}
struct Query {
  bool op;
  int l, r, k;
  int idx, v;
}qry[maxm];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    arr[++sz] = a[i];
  }
  char op[2];
  for (int i = 1; i <= m; ++i) {
    scanf("%s", op);
    qry[i].op = (op[0] == 'Q');
    if (qry[i].op) scanf("%d%d%d", &qry[i].l, &qry[i].r, &qry[i].k);
    else {
      scanf("%d%d", &qry[i].idx, &qry[i].v);
      arr[++sz] = qry[i].v;
    }
  }
  std::sort(arr + 1, arr + sz + 1);
  sz = std::unique(arr + 1, arr + sz + 1) - arr - 1;
  for (int i = 1; i <= n; ++i) Modify(i, 1);
  for (int i = 1; i <= m; ++i) {
    if (qry[i].op) printf("%d\n", arr[Query(qry[i].l, qry[i].r, qry[i].k)]);
    else {
      Modify(qry[i].idx, -1);
      a[qry[i].idx] = qry[i].v;
      Modify(qry[i].idx, 1);
    }
  }
  return 0;
}
