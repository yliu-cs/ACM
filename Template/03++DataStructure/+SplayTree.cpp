const int inf = "Edit"
const int maxn = "Edit";

struct SplayTree {
  int rt, tot;
  int fa[maxn], son[maxn][2];
  int val[maxn], cnt[maxn];
  int sz[maxn];

  void Push(int o) { sz[o] = sz[son[o][0]] + sz[son[o][1]] + cnt[o]; }

  bool Get(int o) { return o == son[fa[o]][1]; }

  void Clear(int o) { son[o][0] = son[o][1] = fa[o] = val[o] = sz[o] = cnt[o] = 0; }

  void Rotate(int o) {
    int p = fa[o], q = fa[p], ck = Get(o);
    son[p][ck] = son[o][ck ^ 1];
    fa[son[o][ck ^ 1]] = p;
    son[o][ck ^ 1] = p;
    fa[p] = o; fa[o] = q;
    if (q) son[q][p == son[q][1]] = o;
    Push(p); Push(o);
  }

  void Splay(int o) {
    for (int f = fa[o]; f = fa[o], f; Rotate(o))
      if (fa[f]) Rotate(Get(o) == Get(f) ? f : o);
    rt = o;
  }

  void Insert(int x) {
    if (!rt) {
      val[++tot] = x;
      cnt[tot]++;
      rt = tot;
      Push(rt);
      return;
    }
    int cur = rt, f = 0;
    while (true) {
      if (val[cur] == x) {
        cnt[cur]++;
        Push(cur); Push(f);
        Splay(cur);
        break;
      }
      f = cur;
      cur = son[cur][val[cur] < x];
      if (!cur) {
        val[++tot] = x;
        cnt[tot]++;
        fa[tot] = f;
        son[f][val[f] < x] = tot;
        Push(tot); Push(f);
        Splay(tot);
        break;
      }
    }
  }

  int GetRank(int x) {
    int ans = 0, cur = rt;
    while (true) {
      if (x < val[cur]) cur = son[cur][0];
      else {
        ans += sz[son[cur][0]];
        if (x == val[cur]) {
          Splay(cur);
          return ans + 1;
        }
        ans += cnt[cur];
        cur = son[cur][1];
      }
    }
  }

  int GetKth(int k) {
    int cur = rt;
    while (true) {
      if (son[cur][0] && k <= sz[son[cur][0]]) cur = son[cur][0];
      else {
        k -= cnt[cur] + sz[son[cur][0]];
        if (k <= 0) return cur;
        cur = son[cur][1];
      }
    }
  }

  // after insert, before delete
  int GetPrev() {
    int cur = son[rt][0];
    while (son[cur][1]) cur = son[cur][1];
    return cur;
  }

  int GetNext() {
    int cur = son[rt][1];
    while (son[cur][0]) cur = son[cur][0];
    return cur;
  }

  void Delete(int x) {
    GetRank(x);
    if (cnt[rt] > 1) {
      cnt[rt]--;
      Push(rt);
      return;
    }
    if (!son[rt][0] && !son[rt][1]) {
      Clear(rt);
      rt = 0;
      return;
    }
    if (!son[rt][0]) {
      int cur = rt;
      rt = son[rt][1];
      fa[rt] = 0;
      Clear(cur);
      return;
    }
    if (!son[rt][1]) {
      int cur = rt;
      rt = son[rt][0];
      fa[rt] = 0;
      Clear(cur);
      return;
    }
    int p = GetPrev(), cur = rt;
    Splay(p);
    fa[son[cur][1]] = p;
    son[p][1] = son[cur][1];
    Clear(cur);
    Push(rt);
  }
};
