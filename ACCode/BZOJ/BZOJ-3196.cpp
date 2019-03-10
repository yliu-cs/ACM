#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
const int maxn = 5e4 + 5;
const int maxm = maxn * 25;

int n;
int arr[maxn];

namespace splay_tree {
    int rt[maxm], tot;
    int fa[maxm], son[maxm][2];
    int val[maxm], cnt[maxm];
    int sz[maxm];

    void Push(int o) {
      sz[o] = sz[son[o][0]] + sz[son[o][1]] + cnt[o];
    }

    bool Get(int o) {
      return o == son[fa[o]][1];
    }

    void Clear(int o) {
      son[o][0] = son[o][1] = fa[o] = val[o] = sz[o] = cnt[o] = 0;
    }

    void Rotate(int o) {
      int p = fa[o], q = fa[p], ck = Get(o);
      son[p][ck] = son[o][ck ^ 1];
      fa[son[o][ck ^ 1]] = p;
      son[o][ck ^ 1] = p;
      fa[p] = o; fa[o] = q;
      if (q) son[q][p == son[q][1]] = o;
      Push(p); Push(o);
    }

    void Splay(int &root, int o) {
      for (int f = fa[o]; (f = fa[o]); Rotate(o))
        if (fa[f]) Rotate(Get(o) == Get(f) ? f : o);
      root = o;
    }

    void Insert(int &root, int x) {
      if (!root) {
        val[++tot] = x;
        cnt[tot]++;
        root = tot;
        Push(root);
        return;
      }
      int cur = root, f = 0;
      while (true) {
        if (val[cur] == x) {
          cnt[cur]++;
          Push(cur); Push(f);
          Splay(root, cur);
          break;
        }
        f = cur;
        cur = son[cur][val[cur] < x];
        if (!cur) {
          val[++tot] = x;
          cnt[tot]++;
          fa[tot] = f;
          son[f][val[f] < x] = tot;
          Push(tot); Push(f);
          Splay(root, tot);
          break;
        }
      }
    }

    int GetRank(int &root, int x) {
      int ans = 0, cur = root;
      while (cur) {
        if (x < val[cur]) {
          cur = son[cur][0];
          continue;
        }
        ans += sz[son[cur][0]];
        if (x == val[cur]) {
          Splay(root, cur);
          return ans;
        }
        if (x > val[cur]) {
          ans += cnt[cur];
          cur = son[cur][1];
        }
      }
      return ans;
    }

    int GetKth(int &root, int k) {
      int cur = root;
      while (true) {
        if (son[cur][0] && k <= sz[son[cur][0]]) cur = son[cur][0];
        else {
          k -= cnt[cur] + sz[son[cur][0]];
          if (k <= 0) return cur;
          cur = son[cur][1];
        }
      }
    }

    int Find(int &root, int x) {
      int ans = 0, cur = root;
      while (cur) {
        if (x < val[cur]) {
          cur = son[cur][0];
          continue;
        }
        ans += sz[son[cur][0]];
        if (x == val[cur]) {
          Splay(root, cur);
          return ans + 1;
        }
        ans += cnt[cur];
        cur = son[cur][1];
      }
    }

    int GetPrev(int &root) {
      int cur = son[root][0];
      while (son[cur][1]) cur = son[cur][1];
      return cur;
    }
    int GetPrevVal(int &root, int x) {
      int ans = -inf, cur = root;
      while (cur) {
        if (x > val[cur]) {
          ans = max(ans, val[cur]);
          cur = son[cur][1];
          continue;
        }
        cur = son[cur][0];
      }
      return ans;
    }

    int GetNext(int &root) {
      int cur = son[root][1];
      while (son[cur][0]) cur = son[cur][0];
      return cur;
    }
    int GetNextVal(int &root, int x) {
      int ans = inf, cur = root;
      while (cur) {
        if (x < val[cur]) {
          ans = min(ans, val[cur]);
          cur = son[cur][0];
          continue;
        }
        cur = son[cur][1];
      }
      return ans;
    }

    void Delete(int &root, int x) {
      Find(root, x);
      if (cnt[root] > 1) {
        cnt[root]--;
        Push(root);
        return;
      }
      if (!son[root][0] && !son[root][1]) {
        Clear(root);
        root = 0;
        return;
      }
      if (!son[root][0]) {
        int cur = root;
        root = son[root][1];
        fa[root] = 0;
        Clear(cur);
        return;
      }
      if (!son[root][1]) {
        int cur = root;
        root = son[root][0];
        fa[root] = 0;
        Clear(cur);
        return;
      }
      int p = GetPrev(root), cur = root;
      Splay(root, p);
      fa[son[cur][1]] = p;
      son[p][1] = son[cur][1];
      Clear(cur);
      Push(root);
    }
};

namespace seg_tree {
    int tree[maxn << 2];

    void Build(int o, int l, int r) {
      for (int i = l; i <= r; ++i) splay_tree::Insert(tree[o], arr[i - 1]);
      if (l == r) return;
      int m = (l + r) >> 1;
      Build(o << 1, l, m);
      Build(o << 1 | 1, m + 1, r);
    }

    void Modify(int o, int l, int r, int ll, int rr, int u, int v) {
      splay_tree::Delete(tree[o], u); splay_tree::Insert(tree[o], v);
      if (l == r) return;
      int m = (l + r) >> 1;
      if (ll <= m) Modify(o << 1, l, m, ll, rr, u, v);
      if (rr > m) Modify(o << 1 | 1, m + 1, r, ll, rr, u, v);
    }

    int QueryRank(int o, int l, int r, int ll, int rr, int v) {
      if (ll <= l && rr >= r) return splay_tree::GetRank(tree[o], v);
      int m = (l + r) >> 1, ans = 0;
      if (ll <= m) ans += QueryRank(o << 1, l, m, ll, rr, v);
      if (rr > m) ans += QueryRank(o << 1 | 1, m + 1, r, ll, rr, v);
      return ans;
    }

    int QueryPrev(int o, int l, int r, int ll, int rr, int v) {
      if (ll <= l && rr >= r) return splay_tree::GetPrevVal(tree[o], v);
      int m = (l + r) >> 1, ans = -inf;
      if (ll <= m) ans = max(ans, QueryPrev(o << 1, l, m, ll, rr, v));
      if (rr > m) ans = max(ans, QueryPrev(o << 1 | 1, m + 1, r, ll, rr, v));
      return ans;
    }

    int QueryNext(int o, int l, int r, int ll, int rr, int v) {
      if (ll <= l && rr >= r) return splay_tree::GetNextVal(tree[o], v);
      int m = (l + r) >> 1, ans = inf;
      if (ll <= m) ans = min(ans, QueryNext(o << 1, l, m, ll, rr, v));
      if (rr > m) ans = min(ans, QueryNext(o << 1 | 1, m + 1, r, ll, rr, v));
      return ans;
    }

    int QueryKth(int ll, int rr, int v) {
      int l = 0, r = 1e8 + 10;
      while (l < r) {
        int m = ((l + r) >> 1) + 1;
        if (QueryRank(1, 1, n, ll, rr, m) < v) l = m;
        else r = m - 1;
      }
      return l;
    }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int m; cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  splay_tree::tot = 0;
  seg_tree::Build(1, 1, n);
  for (int i = 0, op, l, r, pos, k; i < m; ++i) {
    cin >> op;
    if (op == 1) {
      cin >> l >> r >> k;
      cout << seg_tree::QueryRank(1, 1, n, l, r, k) + 1 << endl;
    }
    else if (op == 2) {
      cin >> l >> r >> k;
      cout << seg_tree::QueryKth(l, r, k) << endl;
    }
    else if (op == 3) {
      cin >> pos >> k;
      seg_tree::Modify(1, 1, n, pos, pos, arr[pos - 1], k);
      arr[pos - 1] = k;
    }
    else if (op == 4) {
      cin >> l >> r >> k;
      cout << seg_tree::QueryPrev(1, 1, n, l, r, k) << endl;
    }
    else if (op == 5) {
      cin >> l >> r >> k;
      cout << seg_tree::QueryNext(1, 1, n, l, r, k) << endl;
    }
  }
  return 0;
}

