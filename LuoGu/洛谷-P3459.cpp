// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;

vector<vector<int>> g;

vector<int> in, out;
vector<int> dep;
vector<int> order;

void DfsOrder(int cur, int prev) {
  in[cur] = order.size();
  order.emplace_back(cur);
  for (auto &it : g[cur]) {
    if (it == prev) continue;
    dep[it] = dep[cur] + 1;
    DfsOrder(it, cur);
  }
  out[cur] = order.size() - 1;
}

class seg_tree {
  public:
    typedef int type_t;
    struct node {
      type_t v, lazy;
      node(type_t _v = 0, type_t _lazy = 0): v(_v), lazy(_lazy) {}
    };

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
      if (tree[o].lazy != 0) {
        tree[o << 1].v += (m - l + 1) * tree[o].lazy;
        tree[o << 1 | 1].v += (r - m) * tree[o].lazy;
        tree[o << 1].lazy += tree[o].lazy;
        tree[o << 1 | 1].lazy += tree[o].lazy;
        tree[o].lazy = 0;
      }
    }

    int n;
    vector<node> tree;

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
    void Modify(int ll, int rr) {
      Modify(1, 1, n, ll, rr, -1);
    }

    node Query(int o, int l, int r, int ll, int rr) {
      if (ll <= l && rr >= r) return tree[o];
      Push(o, l, r);
      int m = (l + r) >> 1;
      if (ll <= m) return Query(o << 1, l, m, ll, rr);
      if (rr > m) return Query(o << 1 | 1, m + 1, r, ll, rr);
      Pull(o);
    }
    node Query(int ll, int rr) {
      return Query(1, 1, n, ll, rr);
    }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  g.resize(n);
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    --u; --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  in.resize(n); out.resize(n);
  dep.assign(n, 0);
  DfsOrder(0, -1);
  for (int i = 0; i < order.size(); ++i) order[i] = dep[order[i]];
  seg_tree sgt(order);
  int m; cin >> m;
  m = n + m - 1;
  for (int i = 0, u, v; i < m; ++i) {
    char op; cin >> op;
    if (op == 'W') {
      cin >> u;
      --u;
      cout << sgt.Query(in[u] + 1, in[u] + 1).v << endl;
    }
    else if (op == 'A') {
      cin >> u >> v;
      --u; --v;
      if (dep[u] < dep[v]) swap(u, v);
      sgt.Modify(in[u] + 1, out[u] + 1);
    }
  }
  return 0;
}

