#include <bits/stdc++.h>
const int maxn = 3e5 + 5;
struct LCT {
  int fa[maxn], son[maxn][2];
  int val[maxn], sum[maxn];
  int rev[maxn], stk[maxn];
  void Init(int n) {
    for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
    for (int i = 1; i <= n; ++i) fa[i] = son[i][0] = son[i][1] = rev[i] = 0;
  }
  bool IsRoot(int o) {
    return son[fa[o]][0] != o && son[fa[o]][1] != o;
  }
  bool Get(int o) {
    return son[fa[o]][1] == o;
  }
  void Pull(int o) {
    sum[o] = val[o] ^ sum[son[o][0]] ^ sum[son[o][1]];
  }
  void Push(int o) {
    if (rev[o] != 0) {
      std::swap(son[o][0], son[o][1]);
      if (son[o][0]) rev[son[o][0]] ^= 1;
      if (son[o][1]) rev[son[o][1]] ^= 1;
      rev[o] ^= 1;
    }
  }
  void Rotate(int o) {
    int p = fa[o], q = fa[p], ck = Get(o);
    if (!IsRoot(p)) son[q][Get(p)] = o;
    fa[o] = q;
    son[p][ck] = son[o][ck ^ 1];
    fa[son[p][ck]] = p;
    son[o][ck ^ 1] = p;
    fa[p] = o;
    Pull(p);
    Pull(o);
  }
  void Splay(int o) {
    int top = 0;
    stk[++top] = o;
    for (int i = o; !IsRoot(i); i = fa[i]) stk[++top] = fa[i];
    for (int i = top; i; --i) Push(stk[i]);
    for (int f = fa[o]; !IsRoot(o); Rotate(o), f = fa[o])
      if (!IsRoot(f)) Rotate(Get(o) == Get(f) ? f : o);
  }
  void Access(int o) {
    for (int p = 0; o; p = o, o = fa[o]) {
      Splay(o);
      son[o][1] = p;
      Pull(o);
    }
  }
  int Find(int o) {
    Access(o);
    Splay(o);
    while (son[o][0]) o = son[o][0];
    return o;
  }
  void MakeRoot(int o) {
    Access(o);
    Splay(o);
    rev[o] ^= 1;
  }
  void Link(int u, int v) {
    MakeRoot(u);
    fa[u] = v;
    Splay(u);
  }
  void Cut(int u, int v) {
    MakeRoot(u);
    Access(v);
    Splay(v);
    fa[u] = son[v][0] = 0;
  }
  void Modify(int o, int v) {
    val[o] = v;
    Access(o);
    Splay(o);
  }
  int Query(int u, int v) {
    MakeRoot(v);
    Access(u);
    Splay(u);
    return sum[u];
  }
}T;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  T.Init(n);
  for (int i = 1, opt, u, v; i <= m; ++i) {
    scanf("%d%d%d", &opt, &u, &v);
    if (opt == 0) printf("%d\n", T.Query(u, v));
    else if (opt == 1) T.Link(u, v);
    else if (opt == 2) T.Cut(u, v);
    else T.Modify(u, v);
  }
  return 0;
}
