#include <bits/stdc++.h>
using namespace std;

class seg_tree {
  public:
    int n;
    vector<long long> sum, lazy;

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
      sum.resize(n << 2);
      lazy.resize(n << 2);
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

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<int> arr(n);
  for (auto &it : arr) cin >> it;
  seg_tree sgt(arr);
  for (int i = 0, op, x, y, k; i < m; ++i) {
    cin >> op >> x >> y;
    if (op == 1) {
      cin >> k;
      sgt.Modify(x, y, k);
    }
    else cout << sgt.Query(x, y) << endl;
  }
  return 0;
}
