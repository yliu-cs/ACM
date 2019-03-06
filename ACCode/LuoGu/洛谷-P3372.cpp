#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

class seg_tree {
public:
  typedef long long type_t;
  struct node {
    type_t v, lazy;
    node(type_t _v = 0, type_t _lazy = 0): v(_v), lazy(_lazy) {}
  };

  int n;
  vector<node> tree;

  node Unite(const node &k1, const node &k2) {
    node ans;
    ans.v = k1.v + k2.v;
    return ans;
  }

  inline void Pull(int o) {
    tree[o] = Unite(tree[o << 1], tree[o << 1 | 1]);
  }

  inline void Push(int o, int l, int r) {
    int m = (l + r) >> 1;
    if (tree[o].lazy != 0) {
      tree[o << 1].v += (m - l + 1) * tree[o].lazy;
      tree[o << 1 | 1].v += (r - m) * tree[o].lazy;
      tree[o << 1].lazy += tree[o].lazy;
      tree[o << 1 | 1].lazy += tree[o].lazy;
      tree[o].lazy = 0;
    }
  }

  void Build(int o, int l, int r, const vector<type_t> &v) {
    if (l == r) {
      tree[o].v = v[l - 1];
      return;
    }
    int m = (l + r) >> 1;
    Build(o << 1, l, m, v);
    Build(o << 1 | 1, m + 1, r, v);
    Pull(o);
  }

  seg_tree(const vector<type_t> &v) {
    n = v.size();
    tree.resize(n << 2);
    Build(1, 1, n, v);
  }

  void Modify(int o, int l, int r, int ll, int rr, type_t v) {
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
  void Modify(int ll, int rr, type_t v) {
    Modify(1, 1, n, ll, rr, v);
  }

  node Query(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) return tree[o];
    Push(o, l, r);
    int m = (l + r) >> 1;
    node ans;
    if (ll <= m) ans = Unite(ans, Query(o << 1, l, m, ll, rr));
    if (rr > m) ans = Unite(ans, Query(o << 1 | 1, m + 1, r, ll, rr));
    Pull(o);
    return ans;
  }
  node Query(int ll, int rr) {
    return Query(1, 1, n, ll, rr);
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  long long n, m; cin >> n >> m;
  vector<long long> arr(n);
  for (auto &it : arr) cin >> it;
  seg_tree sgt(arr);
  for (int i = 0, x, y, k, op; i < m; ++i) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> k;
      sgt.Modify(x, y, k);
    }
    else {
      cin >> x >> y;
      cout << sgt.Query(x, y).v << endl;
    }
  }
  return 0;
}

