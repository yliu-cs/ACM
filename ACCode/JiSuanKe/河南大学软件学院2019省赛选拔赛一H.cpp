#include <bits/stdc++.h>
const long long maxn = 3e5 + 5;

class splay_tree {
  public:
    long long rt, tot;
    long long fa[maxn << 1], son[maxn << 1][2];
    long long val[maxn << 1];
    long long sz[maxn << 1], cnt[maxn << 1];

    void Init() {
      rt = tot = 0;
      memset(fa, 0, sizeof(fa)); memset(son, 0, sizeof(son));
      memset(val, 0, sizeof(val)); memset(cnt, 0, sizeof(cnt));
      memset(sz, 0, sizeof(sz));
    }

    void Push(long long o) {
      sz[o] = sz[son[o][0]] + sz[son[o][1]] + cnt[o];
    }

    bool Get(long long o) {
      return o == son[fa[o]][1];
    }

    void Clear(long long o) {
      son[o][0] = son[o][1] = fa[o] = val[o] = sz[o] = cnt[o] = 0;
    }

    void Rotate(long long o) {
      long long p = fa[o], q = fa[p], ck = Get(o);
      son[p][ck] = son[o][ck ^ 1];
      fa[son[o][ck ^ 1]] = p;
      son[o][ck ^ 1] = p;
      fa[p] = o; fa[o] = q;
      if (q) son[q][p == son[q][1]] = o;
      Push(p); Push(o);
    }

    void Splay(long long o) {
      for (long long f = fa[o]; f = fa[o], f; Rotate(o))
        if (fa[f]) Rotate(Get(o) == Get(f) ? f : o);
      rt = o;
    }

    void Insert(long long x) {
      if (!rt) {
        val[++tot] = x;
        cnt[tot]++;
        rt = tot;
        Push(rt);
        return;
      }
      long long cur = rt, f = 0;
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

    long long GetRank(long long x) {
      long long ans = 0, cur = rt;
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

    long long GetKth(long long k) {
      long long cur = rt;
      while (true) {
        if (son[cur][0] && k <= sz[son[cur][0]]) cur = son[cur][0];
        else {
          k -= cnt[cur] + sz[son[cur][0]];
          if (k <= 0) return cur;
          cur = son[cur][1];
        }
      }
    }

    // after insert, before delete
    long long GetPrev() {
      long long cur = son[rt][0];
      while (son[cur][1]) cur = son[cur][1];
      return cur;
    }

    long long GetNext() {
      long long cur = son[rt][1];
      while (son[cur][0]) cur = son[cur][0];
      return cur;
    }

    void Delete(long long x) {
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
        long long cur = rt;
        rt = son[rt][1];
        fa[rt] = 0;
        Clear(cur);
        return;
      }
      if (!son[rt][1]) {
        long long cur = rt;
        rt = son[rt][0];
        fa[rt] = 0;
        Clear(cur);
        return;
      }
      long long p = GetPrev(), cur = rt;
      Splay(p);
      fa[son[cur][1]] = p;
      son[p][1] = son[cur][1];
      Clear(cur);
      Push(rt);
    }
}tree;

int main () {
  long long n, m; scanf("%lld%lld", &n, &m);

  std::vector<long long> arr(n);
  std::vector<long long> pref(n, 0);
  for (long long i = 0; i < n; ++i) {
    scanf("%lld", &arr[i]);
    if (i == 0) pref[i] = arr[i];
    else pref[i] = pref[i - 1] + arr[i];
    tree.Insert(pref[i]);
  }

  long long sum = 0, ans = 0;
  for (long long i = 0; i < n; ++i) {
    long long x = m + sum;
    tree.Insert(x);
    long long cnt = std::max(0ll, tree.GetRank(x) - 1);
    tree.Delete(x);
    ans += cnt;
    sum += arr[i];
    tree.Delete(sum);
  }
  
  printf("%lld\n", ans);
  return 0;
}