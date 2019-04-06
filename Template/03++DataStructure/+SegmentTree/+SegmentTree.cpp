// 求和线段树
template <typename type>
class segtree {
  public:
    struct node {
      type v, lazy;
      node() {v = 0; lazy = 0;}
    };

    int n;
    std::vector<node> tree;

    node Unite(const node &k1, const node &k2) {
      node ret;
      ret.v = k1.v + k2.v;
      return ret;
    }

    void Pull(int o) {
      tree[o] = Unite(tree[o << 1], tree[o << 1 | 1]);
    }

    void Push(int o, int l, int r) {
      int m = (l + r) >> 1;
      if (tree[o].lazy != 0) {
        tree[o << 1].v += (m - l + 1) * tree[o].lazy;
        tree[o << 1 | 1].v += (r - m) * tree[o].lazy;
        tree[o << 1].lazy += tree[o].lazy;
        tree[o << 1 | 1].lazy += tree[o].lazy;
        tree[o].lazy = 0;
      }
    }

    template <typename t>
    void Build(int o, int l, int r, const std::vector<t> &v) {
      if (l == r) {
        tree[o].v = v[l - 1];
        return;
      }
      int m = (l + r) >> 1;
      Build(o << 1, l, m, v);
      Build(o << 1 | 1, m + 1, r, v);
      Pull(o);
    }

    template <typename t>
    segtree(const std::vector<t> &v) {
      n = v.size();
      tree.resize((n << 2) + 1);
      Build(1, 1, n, v);
    }

    template <typename t>
    void Modify(int o, int l, int r, int ll, int rr, t v) {
      if (ll <= l && rr >= r) {
        tree[o].v += (r - l + 1) * v;
        tree[o].lazy += v;
        return;
      }
      Push(o, l, r);
      int m = (l + r) >> 1;
      if (ll <= m) Modify(o << 1, l, m, ll, rr, v);
      if (rr > m) Modify(o << 1 | 1, m + 1, r, ll, rr, v);
      Pull(o);
    }
    template <typename t>
    void Modify(int ll, int rr, t v) {
      Modify(1, 1, n, ll, rr, v);
    }

    node Query(int o, int l, int r, int ll, int rr) {
      if (ll <= l && rr >= r) return tree[o];
      Push(o, l, r);
      int m = (l + r) >> 1;
      node ret;
      if (ll <= m) ret = Unite(ret, Query(o << 1, l, m, ll, rr));
      if (rr > m) ret = Unite(ret, Query(o << 1 | 1, m + 1, r, ll, rr));
      return ret;
    }
    node Query(int ll, int rr) {
      return Query(1, 1, n, ll, rr);
    }
};
