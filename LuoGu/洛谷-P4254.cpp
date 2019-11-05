#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db eps = 1e-9;

int Sgn(db k) {return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);}
int Cmp(db k1, db k2) {return Sgn(k1 - k2);}

struct line {db k, b;};
db F(line k, int x) {return k.k * (x - 1) + k.b;}
line max(line k1, line k2, int x) {return Cmp(F(k1, x), F(k2, x)) < 0 ? k2 : k1;}

struct seg_tree {
  public:
    struct node {
      line v;
      node(line _v = (line){0.0, 0.0}): v(_v) {}
    };

    int n;
    vector<node> tree;

    seg_tree(int _n): n(_n) {
      tree.resize(n << 2);
    }

    void Modify(int o, int l, int r, line v) {
      if (l == r) {
        if (Cmp(F(v, l), F(tree[o].v, l)) > 0) tree[o].v = v;
        return;
      }
      int m = (l + r) >> 1;
      if (Cmp(v.k, tree[o].v.k) > 0) {
        if (Cmp(F(v, m), F(tree[o].v, m)) > 0) {
          Modify(o << 1, l, m, tree[o].v);
          tree[o].v = v;
        }
        else Modify(o << 1 | 1, m + 1, r, v);
      }
      else {
        if (Cmp(F(v, m), F(tree[o].v, m)) > 0) {
          Modify(o << 1 | 1, m + 1, r, tree[o].v);
          tree[o] = v;
        }
        else Modify(o << 1, l, m, v);
      }
    }
    void Modify(line v) {
      Modify(1, 1, n, v);
    }

    node Query(int o, int l, int r, int x) {
      if (l == r) return tree[o].v;
      int m = (l + r) >> 1;
      if (x <= m) return max(tree[o].v, Query(o << 1, l, m, x).v, x);
      return max(tree[o].v, Query(o << 1 | 1, m + 1, r, x).v, x);
    }
    node Query(int x) {
      return Query(1, 1, n, x);
    }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  seg_tree sgt(500005);
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    string op; cin >> op;
    if (op == "Query") {
      int t; cin >> t;
      cout << (int)(F(sgt.Query(t).v, t) / 100.0) << endl;
    }
    else {
      db b, k; cin >> b >> k;
      sgt.Modify((line){k, b});
    }
  }
  return 0;
}