const int maxn = "Edit";

class FuncSegTree {
  public:
    int tot;
    int rt[maxn];
    int lson[maxn << 5], rson[maxn << 5];
    int cnt[maxn << 5];

    int Build(int l, int r) {
      int o = ++tot, m = (l + r) >> 1;
      cnt[o] = 0;
      if (l != r) {
        lson[o] = Build(l, m);
        rson[o] = Build(m + 1, r);
      }
      return o;
    }

    int Modify(int prev, int l, int r, int v) {
      int o = ++tot, m = (l + r) >> 1;
      lson[o] = lson[prev];
      rson[o] = rson[prev];
      cnt[o] = cnt[prev] + 1;
      if (l != r) {
        if (v <= m) lson[o] = Modify(lson[o], l, m, v);
        else rson[o] = Modify(rson[o], m + 1, r, v);
      }
      return o;
    }

    // 区间[u+1,v]静态第k小
    int Query(int u, int v, int l, int r, int k) {
      if (l == r) return l;
      int m = (l + r) >> 1;
      int num = cnt[lson[v]] - cnt[lson[u]];
      if (num >= k) return Query(lson[u], lson[v], l, m, k);
      return Query(rson[u], rson[v], m + 1, r, k - num);
    }

    // 区间[u+1,v]内[s,t]数量
    int Query(int u, int v, int s, int t, int l, int r) {
      if (s <= l && t >= r) return cnt[v] - cnt[u];
      int m = (l + r) >> 1, ret = 0;
      if (s <= m) ret += Query(lson[u], lson[v], s, t, l, m);
      if (t > m) ret += Query(rson[u], rson[v], s, t, m + 1, r);
      return ret;
    }
};


