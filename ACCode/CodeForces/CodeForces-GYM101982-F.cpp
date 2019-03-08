#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> x;
int Get(int k) {
  return lower_bound(x.begin(), x.end(), k) - x.begin();
}

class seg_tree {
public:
  struct node {
    int v, lazy;
    node(int _v = 0, int _lazy = 0): v(_v), lazy(_lazy) {}
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
      tree[o << 1].v = x[m] - x[l - 1] - tree[o << 1].v;
      tree[o << 1 | 1].v = x[r] - x[m] - tree[o << 1 | 1].v;
      tree[o << 1].lazy ^= 1;
      tree[o << 1 | 1].lazy ^= 1;
      tree[o].lazy = 0;
    }
  }

  int n;
  vector<node> tree;

  void Build(int o, int l, int r) {
    if (l == r) return;
    int m = (l + r) >> 1;
    Build(o << 1, l, m);
    Build(o << 1 | 1, m + 1, r);
    Pull(o);
  }

  seg_tree(int _n): n(_n) {
    tree.resize(n << 2);
    Build(1, 1, n);
  }

  void Modify(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) {
      tree[o].v = x[r] - x[l - 1] - tree[o].v;
      tree[o].lazy ^= 1;
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
    node ans;
    if (ll <= m) ans = Unite(ans, Query(o << 1, l, m, ll, rr));
    if (rr > m) ans = Unite(ans, Query(o << 1 | 1, m + 1, r, ll, rr));
    Pull(o);
    return ans;
  }
  node Query() {
    return Query(1, 1, n, 1, n);
  }
};

struct seg {int l, r, h, flag;};
bool operator < (seg k1, seg k2) {return k1.h < k2.h;}
vector<seg> s;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  for (int i = 0, x1, y1, x2, y2; i < n; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    x.emplace_back(x1); x.emplace_back(x2);
    s.emplace_back((seg){x1, x2, y1, 1});
    s.emplace_back((seg){x1, x2, y2, -1});
  }
  sort(s.begin(), s.end());
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  seg_tree sgt(x.size());
  ll ans = 0;
  for (int i = 0, l, r; i < s.size() - 1; ++i) {
    l = Get(s[i].l), r = Get(s[i].r);
    sgt.Modify(l + 1, r);
    ans += (ll)sgt.Query().v * (s[i + 1].h - s[i].h);
  }
  cout << ans << endl;
  return 0;
}

