#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 1000000;

class splay_tree {
  public:
    int rt, tot;
    int fa[maxn], son[maxn][2];
    int val[maxn], cnt[maxn];
    int sz[maxn];

    splay_tree() {
      rt = tot = 0;
    }

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

    void Splay(int o) {
      for (int f = fa[o]; f = fa[o], f; Rotate(o))
        if (fa[f]) Rotate(Get(o) == Get(f) ? f : o);
      rt = o;
    }

    void Insert(int x) {
      if (!rt) {
        val[++tot] = x;
        cnt[tot]++;
        rt = tot;
        Push(rt);
        return;
      }
      int cur = rt, f = 0;
      while (true) {
        if (val[cur] == x) {
          cnt[cur]++;
          Push(cur); Push(f);
          Splay(cur);
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
          Splay(tot);
          break;
        }
      }
    }

    int GetRank(int x) {
      int ans = 0, cur = rt;
      while (true) {
        if (x < val[cur]) cur = son[cur][0];
        else {
          ans += sz[son[cur][0]];
          if (x == val[cur]) {
            Splay(cur);
            return ans + 1;
          }
          ans += cnt[cur];
          cur = son[cur][1];
        }
      }
    }

    int GetKth(int k) {
      int cur = rt;
      while (true) {
        if (son[cur][0] && k <= sz[son[cur][0]]) cur = son[cur][0];
        else {
          k -= cnt[cur] + sz[son[cur][0]];
          if (k <= 0) return cur;
          cur = son[cur][1];
        }
      }
    }

    // after insert
    int GetPrev() {
      int cur = son[rt][0];
      while (son[cur][1]) cur = son[cur][1];
      return cur;
    }

    int GetNext() {
      int cur = son[rt][1];
      while (son[cur][0]) cur = son[cur][0];
      return cur;
    }

    void Delete(int x) {
      GetRank(x);
      if (cnt[rt] > 1) {
        cnt[rt]--;
        Push(rt);
        return;
      }
      if (!son[rt][0] && !son[rt][1]) {
        Clear(rt);
        rt = 0;
        return;
      }
      if (!son[rt][0]) {
        int cur = rt;
        rt = son[rt][1];
        fa[rt] = 0;
        Clear(cur);
        return;
      }
      if (!son[rt][1]) {
        int cur = rt;
        rt = son[rt][0];
        fa[rt] = 0;
        Clear(cur);
        return;
      }
      int p = GetPrev(), cur = rt;
      Splay(p);
      fa[son[cur][1]] = p;
      son[p][1] = son[cur][1];
      Clear(cur);
      Push(rt);
    }
};

splay_tree spt;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  int cur = 0, ans = 0;
  spt.Insert(inf); spt.Insert(-inf);
  for (int i = 0, a, b; i < n; ++i) {
    cin >> a >> b;
    if (cur == 0) {
      spt.Insert(b);
      if (a == 0) ++cur;
      else --cur;
    }
    else if (cur > 0) {
      if (a == 0) {
        spt.Insert(b);
        ++cur;
      }
      else {
        spt.Insert(b);
        int pre = spt.val[spt.GetPrev()], nxt = spt.val[spt.GetNext()];
        if (abs(b - pre) <= abs(b - nxt)) {
          ans = (ans + abs(b - pre)) % mod;
          spt.Delete(pre);
        }
        else {
          ans = (ans + abs(b - nxt)) % mod;
          spt.Delete(nxt);
        }
        spt.Delete(b);
        --cur;
      }
    }
    else {
      if (a == 0) {
        spt.Insert(b);
        int pre = spt.val[spt.GetPrev()], nxt = spt.val[spt.GetNext()];
        if (abs(b - pre) <= abs(b - nxt)) {
          ans = (ans + abs(b - pre)) % mod;
          spt.Delete(pre);
        }
        else {
          ans = (ans + abs(b - nxt)) % mod;
          spt.Delete(nxt);
        }
        spt.Delete(b);
        ++cur;
      }
      else {
        spt.Insert(b);
        --cur;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

