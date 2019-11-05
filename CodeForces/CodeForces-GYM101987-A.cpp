#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

namespace SegTree {
  int v[maxn << 2], lazy[maxn << 2];

  void Pull(int o) {
    v[o] = max(v[o << 1], v[o << 1 | 1]);
  }

  void Push(int o, int l, int r) {
    int m = (l + r) >> 1;
    if (lazy[o] != 0) {
      v[o << 1] += lazy[o];
      v[o << 1 | 1] += lazy[o];
      lazy[o << 1] += lazy[o];
      lazy[o << 1 | 1] += lazy[o];
      lazy[o] = 0;
    }
  }

  void Build(int o, int l, int r) {
    v[o] = lazy[o] = 0;
    if (l == r) return;
    int m = (l + r) >> 1;
    Build(o << 1, l, m);
    Build(o << 1 | 1, m + 1, r);
    Pull(o);
  }

  void Modify(int o,int l, int r, int ll, int rr, int x) {
    if (ll <= l && rr >= r) {
      v[o] += x;
      lazy[o] += x;
      return;
    }
    int m = (l + r) >> 1;
    Push(o, l, r);
    if (ll <= m) Modify(o << 1, l, m, ll, rr, x);
    if (rr > m) Modify(o << 1 | 1, m + 1, r, ll, rr, x);
    Pull(o);
  }

  int Query(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) return v[o];
    int m = (l + r) >> 1;
    Push(o, l, r);
    if (ll <= m) return Query(o << 1, l, m, ll, rr);
    if (rr > m) return Query(o << 1 | 1, m + 1, r, ll, rr);
  }
};

namespace Hash {
  int size;
  vector<int> arr;

  void Init(const vector<int> &v) {
    arr.assign(v.begin(), v.end());
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    size = arr.size();
  }

  int Get(int k) {
    return lower_bound(arr.begin(), arr.end(), k) - arr.begin();
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<int> h; vector<pair<int, int>> seg;
  for (int i = 0, x1, y1, x2, y2; i < n; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    seg.emplace_back(make_pair(y2, y1));
    h.emplace_back(y1); h.emplace_back(y2);
  }
  Hash::Init(h);
  SegTree::Build(1, 1, Hash::size);
  vector<vector<int>> in(Hash::size), out(Hash::size);
  vector<int> l, r;
  for (auto it : seg) {
    l.emplace_back(Hash::Get(it.first));
    r.emplace_back(Hash::Get(it.second));
  }
  for (int i = 0; i < n; ++i) {
    in[l[i]].emplace_back(i);
    out[r[i]].emplace_back(i);
    SegTree::Modify(1, 1, Hash::size, l[i] + 1, r[i] + 1, 1);
  }
  int ans = 0;
  vector<int> res(Hash::size);
  for (int i = 0; i < Hash::size; ++i) res[i] = SegTree::Query(1, 1, Hash::size, i + 1, i + 1);
  for (int i = 0; i < Hash::size; ++i) {
    for (auto it : in[i])
      SegTree::Modify(1, 1, Hash::size, l[it] + 1, r[it] + 1, -1);
    ans = max(ans, res[i] + SegTree::v[1]);
    for (auto it : out[i])
      SegTree::Modify(1, 1, Hash::size, l[it] + 1, r[it] + 1, 1);
  }
  cout << ans << endl;
  return 0;
}

