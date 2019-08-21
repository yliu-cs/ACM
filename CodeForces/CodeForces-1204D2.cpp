// Author: Tony5t4rk Time: 2019-08-20 23:33:26 
#include <bits/stdc++.h>
struct SegTree {
  typedef int type_t;
  struct node {
    type_t cnt0, cnt1, rise, fall, lazy;
    node(type_t _cnt0 = 0, type_t _cnt1 = 0,
         type_t _rise = 1, type_t _fall = 1,
         type_t _lazy = 0): cnt0(_cnt0), cnt1(_cnt1), 
                            rise(_rise), fall(_fall),
                            lazy(_lazy) {}
  };
  int n;
  std::vector<node> tree;
  node Unite(const node &k1, const node &k2) {
    node ans;
    ans.cnt0 = k1.cnt0 + k2.cnt0;
    ans.cnt1 = k1.cnt1 + k2.cnt1;
    ans.rise = std::max({k1.rise + k2.cnt1, k1.cnt0 + k2.cnt1, k1.cnt0 + k2.rise});
    ans.fall = std::max({k1.fall + k2.cnt0, k1.cnt1 + k2.cnt0, k1.cnt1 + k2.fall});
    return ans;
  }
  void Pull(int o) {
    tree[o] = Unite(tree[o << 1], tree[o << 1 | 1]);
  }
  void Push(int o, int l, int r) {
    if (tree[o].lazy != 0) {
      std::swap(tree[o << 1].cnt0, tree[o << 1].cnt1);
      std::swap(tree[o << 1].rise, tree[o << 1].fall);
      std::swap(tree[o << 1 | 1].cnt0, tree[o << 1 | 1].cnt1);
      std::swap(tree[o << 1 | 1].rise, tree[o << 1 | 1].fall);
      tree[o << 1].lazy = !tree[o << 1].lazy;
      tree[o << 1 | 1].lazy = !tree[o << 1 | 1].lazy;
      tree[o].lazy = 0;
    }
  }
  void Build(int o, int l, int r, const std::vector<type_t> &v) {
    if (l == r) {
      tree[o].cnt0 = (v[l - 1] == 0);
      tree[o].cnt1 = (v[l - 1] == 1);
      return;
    }
    int m = (l + r) >> 1;
    Build(o << 1, l, m, v);
    Build(o << 1 | 1, m + 1, r, v);
    Pull(o);
  }
  SegTree(const std::vector<type_t> &v) {
    n = v.size();
    tree.resize(n << 2);
    Build(1, 1, n, v);
  }
  void Modify(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) {
      std::swap(tree[o].cnt0, tree[o].cnt1);
      std::swap(tree[o].rise, tree[o].fall);
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
  node Query(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) return tree[o];
    Push(o, l, r);
    int m = (l + r) >> 1;
    if (rr <= m) return Query(o << 1, l, m, ll, rr);
    else if (ll > m) return Query(o << 1 | 1, m + 1, r, ll, rr);
    else return Unite(Query(o << 1, l, m, ll, rr), Query(o << 1 | 1, m + 1, r, ll, rr));
    Pull(o);
  }
  node Query(int ll, int rr) {
    return Query(1, 1, n, ll, rr);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s;
  std::cin >> s;
  int n = s.length();
  std::vector<int> arr;
  for (auto &c : s) arr.push_back(c - '0');
  std::vector<int> ans(arr.begin(), arr.end());
  SegTree T1(arr), T2(ans);
  for (int i = n - 1; i >= 0; --i) {
    if (arr[i] == 0) continue;
    T2.Modify(i + 1, i + 1);
    if (T1.Query(i + 1, n).rise == T2.Query(i + 1, n).rise) ans[i] ^= 1;
    else T2.Modify(i + 1, i + 1);
  }
  for (auto &v : ans) std::cout << v;
  std::cout << '\n';
  return 0;
}
