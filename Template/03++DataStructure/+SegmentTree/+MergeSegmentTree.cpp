// BZOJ2212: 交换左右子树后最小逆序对
#include <bits/stdc++.h>
const int maxn = 1e7 + 5;
 
template <typename t>
inline bool Read(t &ret) {
  char c; int sgn;
  if (c = getchar(), c == EOF) return false;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return true;
}
 
struct node {
  int sz, lson, rson;
  node() {sz = lson = rson = 0;}
};
 
int n;
int tot;
node tree[maxn];
long long ans1, ans2;
long long ans;
 
int Build(int l, int r, int c) {
  tree[++tot].sz = 1;
  if (l == r) return tot;
  int m = (l + r) >> 1, o = tot;
  if (c <= m) tree[o].lson = Build(l, m, c);
  else tree[o].rson = Build(m + 1, r, c);
  return o;
}
 
int Merge(int l, int r, int x, int y) {
  if (!x || !y) return x + y;
  if (l == r) {
    tree[++tot].sz = tree[x].sz + tree[y].sz;
    return tot;
  }
  ans1 += 1ll * tree[tree[x].rson].sz * tree[tree[y].lson].sz;
  ans2 += 1ll * tree[tree[x].lson].sz * tree[tree[y].rson].sz;
  int m = (l + r) >> 1, o = ++tot;
  tree[o].lson = Merge(l, m, tree[x].lson, tree[y].lson);
  tree[o].rson = Merge(m + 1, r, tree[x].rson, tree[y].rson);
  tree[o].sz = tree[x].sz + tree[y].sz;
  return o;
}
 
int Dfs() {
  int c = 0; Read(c);
  if (c) return Build(1, n, c);
  int o = Merge(1, n, Dfs(), Dfs());
  ans += std::min(ans1, ans2);
  ans1 = ans2 = 0;
  return o;
}
 
int main() {
 
  Read(n);
  Dfs();
  printf("%lld", ans);
 
  return 0;
}

