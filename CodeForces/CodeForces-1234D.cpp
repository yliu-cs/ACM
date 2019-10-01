// Author: Tony5t4rk Time: 2019-10-01 23:50:54 
#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int maxa = 30;
int Get(char x) { return x - 'a'; }
struct SegTree {
  struct Node {
    bool val[maxa];
    Node() { memset(val, false, sizeof(val)); }
  };
  int n;
  Node tree[maxn * 4];
  Node Unite(const Node &k1, const Node &k2) {
    Node ret;
    for (int i = 0; i < maxa; ++i) ret.val[i] = k1.val[i] | k2.val[i];
    return ret;
  }
  void Pull(int o) {
    tree[o] = Unite(tree[o * 2], tree[o * 2 + 1]);
  }
  void Build(int o, int l, int r, char str[]) {
    if (l == r) {
      tree[o].val[Get(str[l])] = true;
      return;
    }
    int m = (l + r) / 2;
    Build(o * 2, l, m, str);
    Build(o * 2 + 1, m + 1, r, str);
    Pull(o);
  }
  void Build(char str[]) {
    Build(1, 1, n, str);
  }
  void Modify(int o, int l, int r, int idx, char c, bool v) {
    if (l == r) {
      tree[o].val[Get(c)] = v;
      return;
    }
    int m = (l + r) / 2;
    if (idx <= m) Modify(o * 2, l, m, idx, c, v);
    else Modify(o * 2 + 1, m + 1, r, idx, c, v);
    Pull(o);
  }
  void Modify(int idx, char c, bool v) {
    Modify(1, 1, n, idx, c, v);
  }
  Node Query(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) return tree[o];
    int m = (l + r) / 2;
    Node ret;
    if (ll <= m) ret = Unite(ret, Query(o * 2, l, m, ll, rr));
    if (rr > m) ret = Unite(ret, Query(o * 2 + 1, m + 1, r, ll, rr));
    return ret;
  }
  int Query(int ll, int rr) {
    Node ans = Query(1, 1, n, ll, rr);
    int ret = 0;
    for (int i = 0; i < maxa; ++i) if (ans.val[i]) ++ret;
    return ret;
  }
}T;
char str[maxn];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  scanf("%s", str + 1);
  T.n = std::strlen(str + 1);
  T.Build(str);
  int m; scanf("%d", &m);
  for (int i = 1, op; i <= m; ++i) {
    scanf("%d", &op);
    if (op == 1) {
      int pos; char c; scanf("%d %c", &pos, &c);
      T.Modify(pos, str[pos], false);
      T.Modify(pos, c, true);
      str[pos] = c;
    }
    else if (op == 2) {
      int l, r; scanf("%d%d", &l, &r);
      printf("%d\n", T.Query(l, r));
    }
  }
  return 0;
}
