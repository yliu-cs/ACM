#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int inf = 2e9 + 5;
struct LCT {
  int fa[maxn], son[maxn][2];
  int val[maxn], max[maxn];
  int rev[maxn], stk[maxn];
  bool IsRoot(int o) {
    return son[fa[o]][0] != o && son[fa[o]][1] != o;
  }
  bool Get(int o) {
    return son[fa[o]][1] == o;
  }
  void Pull(int o) {
    max[o] = o;
    if (son[o][0] && val[max[son[o][0]]] > val[max[o]]) max[o] = max[son[o][0]];
    if (son[o][1] && val[max[son[o][1]]] > val[max[o]]) max[o] = max[son[o][1]];
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
    return max[u];
  }
};
LCT lct;
struct edge { int u, v, a, b; };
bool operator < (const edge &k1, const edge &k2) {
  return k1.a < k2.a;
}
edge g[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d%d%d", &g[i].u, &g[i].v, &g[i].a, &g[i].b);
  std::sort(g + 1, g + m + 1);
  int ans = inf;
  for (int i = 1; i <= m; ++i) {
    int u = g[i].u, v = g[i].v, a = g[i].a, b = g[i].b;
    if (lct.Find(u) == lct.Find(v)) {
      int w = lct.Query(u, v);
      if (lct.val[w] <= b) {
        if (lct.Find(1) == lct.Find(n)) ans = std::min(ans, a + lct.val[lct.Query(1, n)]);
        continue;
      }
      lct.Cut(w, g[w - n].u);
      lct.Cut(w, g[w - n].v);
    }
    lct.val[i + n] = b;
    lct.max[i + n] = i + n;
    lct.Link(u, i + n);
    lct.Link(v, i + n);
    if (lct.Find(1) == lct.Find(n)) ans = std::min(ans, a + lct.val[lct.Query(1, n)]);
  }
  printf("%d\n", ans == inf ? -1 : ans);
  return 0;
}

