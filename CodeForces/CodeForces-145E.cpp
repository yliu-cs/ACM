#include <bits/stdc++.h>
using namespace std;

class seg_tree {
public:
  typedef int type_t;
  struct node {
    type_t cnt4, cnt7, rise, fall, lazy;
    node(type_t _cnt4 = 0, type_t _cnt7 = 0,
         type_t _rise = 1, type_t _fall = 1,
         type_t _lazy = 0): cnt4(_cnt4), cnt7(_cnt7), 
                            rise(_rise), fall(_fall),
                            lazy(_lazy) {}
  };

  int n;
  vector<node> tree;

  node Unite(const node &k1, const node &k2) {
    node ans;
    ans.cnt4 = k1.cnt4 + k2.cnt4;
    ans.cnt7 = k1.cnt7 + k2.cnt7;
    ans.rise = max(k1.rise + k2.cnt7, max(k1.cnt4 + k2.cnt7, k1.cnt4 + k2.rise));
    ans.fall = max(k1.fall + k2.cnt4, max(k1.cnt7 + k2.cnt4, k1.cnt7 + k2.fall));
    return ans;
  }

  void Pull(int o) {
    tree[o] = Unite(tree[o << 1], tree[o << 1 | 1]);
  }

  void Push(int o, int l, int r) {
    if (tree[o].lazy != 0) {
      swap(tree[o << 1].cnt4, tree[o << 1].cnt7);
      swap(tree[o << 1].rise, tree[o << 1].fall);
      swap(tree[o << 1 | 1].cnt4, tree[o << 1 | 1].cnt7);
      swap(tree[o << 1 | 1].rise, tree[o << 1 | 1].fall);
      tree[o << 1].lazy = !tree[o << 1].lazy;
      tree[o << 1 | 1].lazy = !tree[o << 1 | 1].lazy;
      tree[o].lazy = 0;
    }
  }

  void Build(int o, int l, int r, const vector<type_t> &v) {
    if (l == r) {
      tree[o].cnt4 = (v[l - 1] == 4);
      tree[o].cnt7 = (v[l - 1] == 7);
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

  void Modify(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) {
      swap(tree[o].cnt4, tree[o].cnt7);
      swap(tree[o].rise, tree[o].fall);
      tree[o].lazy = !tree[o].lazy;
      return;
    }
    Push(o, l, r);
    int m = (l + r) >> 1;
    if (ll <= m) Modify(o << 1, l, m, ll, rr);
    if (rr > m) Modify(o << 1 | 1, m + 1, r, ll, rr);
    Pull(o);
  }
  void Modify(int ll, int rr) {
    Modify(1, 1, n, ll, rr);
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    char x; cin >> x;
    arr[i] = x - '0';
  }
  seg_tree sgt(arr);
  for (int i = 0, l, r; i < m; ++i) {
    string s; cin >> s;
    if (s == "count") cout << sgt.tree[1].rise << endl;
    else {
      cin >> l >> r;
      sgt.Modify(l, r);
    }
  }
  return 0;
}

