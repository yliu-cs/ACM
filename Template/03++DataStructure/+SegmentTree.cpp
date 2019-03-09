// 求和线段树
const int maxn = "Edit"

class seg_tree {
  public:
    int n;
    long long sum[maxn << 2], lazy[maxn << 2];

    void Pull(int o) {
      sum[o] = sum[o << 1] + sum[o << 1 | 1];
    }

    void Push(int o, int l, int r) {
      int m = (l + r) >> 1;
      if (lazy[o] != 0) {
        sum[o << 1] += (m - l + 1) * lazy[o];
        sum[o << 1 | 1] += (r - m) * lazy[o];
        lazy[o << 1] += lazy[o];
        lazy[o << 1 | 1] += lazy[o];
        lazy[o] = 0;
      }
    }

    template <typename t>
    void Build(int o, int l, int r, const vector<t> &v) {
      sum[o] = 0; lazy[o] = 0;
      if (l == r) {
        sum[o] = v[l - 1];
        return;
      }
      int m = (l + r) >> 1;
      Build(o << 1, l, m, v);
      Build(o << 1 | 1, m + 1, r, v);
      Pull(o);
    }

    template <typename t>
    seg_tree(const vector<t> &v) {
      n = v.size();
      Build(1, 1, n, v);
    }

    template <typename t>
    void Modify(int o, int l, int r, int ll, int rr, t v) {
      if (ll <= l && rr >= r) {
        sum[o] += (r - l + 1) * v;
        lazy[o] += v;
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

    long long Query(int o, int l, int r, int ll, int rr) {
      if (ll <= l && rr >= r) return sum[o];
      Push(o, l, r);
      int m = (l + r) >> 1;
      long long ans = 0;
      if (ll <= m) ans += Query(o << 1, l, m, ll, rr);
      if (rr > m) ans += Query(o << 1 | 1, m + 1, r, ll, rr);
      return ans;
    }
    long long Query(int ll, int rr) {
      return Query(1, 1, n, ll, rr);
    }
};
