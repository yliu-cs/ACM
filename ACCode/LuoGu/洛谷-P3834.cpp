#include <bits/stdc++.h>
using namespace std;

class func_seg_tree {
  public:
    int tot;
    vector<int> rt;
    vector<int> lson, rson;
    vector<int> cnt;

    int Build(int l, int r) {
      int t = ++tot;
      int m = (l + r) >> 1;
      if (l != r) {
        lson[t] = Build(l, m);
        rson[t] = Build(m + 1, r);
      }
      return t;
    }

    func_seg_tree(int n) {
      tot = 0;
      rt.resize(n + 5);
      lson.resize((n << 5) + 5);
      rson.resize((n << 5) + 5);
      cnt.resize((n << 5) + 5);
      rt[0] = Build(1, n);
    }

    int Modify(int prev, int l, int r, int x) {
      int t = ++tot;
      lson[t] = lson[prev]; rson[t] = rson[prev];
      cnt[t] = cnt[prev] + 1;
      int m = (l + r) >> 1;
      if (l != r) {
        if (x <= m) lson[t] = Modify(lson[t], l, m, x);
        else rson[t] = Modify(rson[t], m + 1, r, x);
      }
      return t;
    }

    int Query(int u, int v, int l, int r, int k) {
      if (l == r) return l;
      int m = (l + r) >> 1;
      int num = cnt[lson[v]] - cnt[lson[u]];
      if (num >= k) return Query(lson[u], lson[v], l, m, k);
      return Query(rson[u], rson[v], m + 1, r, k - num);
    }
};

class Hash {
  public:
    int size;
    vector<int> arr;

    Hash(const vector<int> &v) {
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
  int n, m; cin >> n >> m;
  vector<int> init(n);
  for (auto &it : init) cin >> it;
  Hash h(init);
  func_seg_tree fsgt(n);
  for (int i = 1; i <= n; ++i) {
    fsgt.rt[i] = fsgt.Modify(fsgt.rt[i - 1], 1, h.size, h.Get(init[i - 1]) + 1);
  }
  for (int i = 0, l, r, k; i < m; ++i) {
    cin >> l >> r >> k;
    cout << h.arr[fsgt.Query(fsgt.rt[l - 1], fsgt.rt[r], 1, h.size, k) - 1] << endl;
  }
  return 0;
}

