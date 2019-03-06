#include <bits/stdc++.h>
using namespace std;

int mod;

class seg_tree {
public:
  typedef long long type_t;
  struct node {
    type_t v, add, mul;
    node(type_t _v = 0, type_t _add = 0, type_t _mul = 1): v(_v), add(_add), mul(_mul) {}
  };

  int n;
  vector<node> tree;

  node Unite(const node &k1, const node &k2) {
    node ans;
    ans.v = k1.v + k2.v;
    return ans;
  }

  void Pull(int o) {
    tree[o] = Unite(tree[o << 1], tree[o << 1 | 1]);
  }

  void Push(int o, int l, int r) {
    int m = (l + r) >> 1;
    if (tree[o].mul != 1) {
      tree[o << 1].add = (tree[o << 1].add * tree[o].mul) % mod;
      tree[o << 1 | 1].add = (tree[o << 1 | 1].add * tree[o].mul) % mod;
      tree[o << 1].mul = (tree[o << 1].mul * tree[o].mul) % mod;
      tree[o << 1 | 1].mul = (tree[o << 1 | 1].mul * tree[o].mul) % mod;
      tree[o << 1].v = (tree[o << 1].v * tree[o].mul) % mod;
      tree[o << 1 | 1].v = (tree[o << 1 | 1].v * tree[o].mul) % mod;
      tree[o].mul = 1;
    }
    if (tree[o].add != 0) {
      tree[o << 1].v += (m - l + 1) * tree[o].add;
      tree[o << 1 | 1].v += (r - m) * tree[o].add;
      tree[o << 1].add += tree[o].add;
      tree[o << 1 | 1].add += tree[o].add;
      tree[o].add = 0;
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
  
  void ModifyAdd(int o, int l, int r, int ll, int rr, type_t v) {
    if (ll <= l && rr >= r) {
      tree[o].v += (r - l + 1) * v;
      tree[o].add += v;
      return;
    }
    Push(o, l, r);
    int m = (l + r) >> 1;
    if (ll <= m) ModifyAdd(o << 1, l, m, ll, rr, v);
    if (rr > m) ModifyAdd(o << 1 | 1, m + 1, r, ll, rr, v);
    Pull(o);
  }
  void ModifyAdd(int ll, int rr, type_t v) {
    ModifyAdd(1, 1, n, ll, rr, v);
  }

  void ModifyMul(int o, int l, int r, int ll, int rr, type_t v) {
    if (ll <= l && rr >= r) {
      tree[o].v = (tree[o].v * v) % mod;
      tree[o].add = (tree[o].add * v) % mod;
      tree[o].mul = (tree[o].mul * v) % mod;
      return;
    }
    Push(o, l, r);
    int m = (l + r) >> 1;
    if (ll <= m) ModifyMul(o << 1, l, m, ll, rr, v);
    if (rr > m) ModifyMul(o << 1 | 1, m + 1, r, ll, rr, v);
    Pull(o);
  }
  void ModifyMul(int ll, int rr, type_t v) {
    ModifyMul(1, 1, n, ll, rr, v);
  }

  node Query(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) return tree[o];
    Push(o, l, r);
    int m = (l + r) >> 1;
    node ans;
    if (ll <= m) ans = Unite(ans, Query(o << 1, l, m, ll, rr));
    if (rr > m) ans = Unite(ans, Query(o << 1 | 1, m + 1, r, ll, rr));
    return ans;
  }
  node Query(int ll, int rr) {
    return Query(1, 1, n, ll, rr);
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m >> mod;
  vector<long long> arr(n);
  for (auto &it : arr) cin >> it;
  seg_tree sgt(arr);
  sgt.Build(1, 1, n, arr);
  for (int i = 0, op, x, y, k; i < m; ++i) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> k;
      sgt.ModifyMul(x, y, k);
    }
    else if (op == 2) {
      cin >> x >> y >> k;
      sgt.ModifyAdd(x, y, k);
    }
    else {
      cin >> x >> y;
      cout << sgt.Query(x, y).v % mod << endl;
    }
  }
  return 0;
}

