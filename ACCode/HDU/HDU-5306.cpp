#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

template <class T>
inline bool Read(T &ans) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) {
        return false;
    }
    while (c != '-' && (c < '0' || c > '9')) {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ans = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') {
        ans = ans * 10 + (c - '0');
    }
    ans *= sgn;
    return true;
}

class seg_tree{
  public:
    int ma[maxn << 2], t[maxn << 2], se[maxn << 2];
    long long sum[maxn << 2];

    void Pull(int o) {
      sum[o] = sum[o << 1] + sum[o << 1 | 1];
      ma[o] = max(ma[o << 1], ma[o << 1 | 1]);
      se[o] = max(se[o << 1], se[o << 1 | 1]);
      t[o] = 0;
      if (ma[o << 1] != ma[o << 1 | 1]) se[o] = max(se[o], min(ma[o << 1], ma[o << 1 | 1]));
      if (ma[o] == ma[o << 1]) t[o] += t[o << 1];
      if (ma[o] == ma[o << 1 | 1]) t[o] += t[o << 1 | 1];
    }

    void Push(int o, int l, int r) {
      int m = (l + r) >> 1;
      if (ma[o] < ma[o << 1]) {
        sum[o << 1] += 1ll * (ma[o] - ma[o << 1]) * t[o << 1];
        ma[o << 1] = ma[o];
      }
      if (ma[o] < ma[o << 1 | 1]) {
        sum[o << 1 | 1] += 1ll * (ma[o] - ma[o << 1 | 1]) * t[o << 1 | 1];
        ma[o << 1 | 1] = ma[o];
      }
    }

    void Build(int o, int l, int r) {
      if (l == r) {
        Read(sum[o]);
        ma[o] = sum[o];
        t[o] = 1; se[o] = -1;
        return;
      }
      int m = (l + r) >> 1;
      Build(o << 1, l, m);
      Build(o << 1 | 1, m + 1, r);
      Pull(o);
    }

    void Modify(int o, int l, int r, int ll, int rr, int v) {
      if (ll <= l && rr >= r && v > se[o]) {
        if (v < ma[o]) {
          sum[o] += 1ll * (v - ma[o]) * t[o];
          ma[o] = v;
        }
        return;
      }
      Push(o, l, r);
      int m = (l + r) >> 1;
      if (ll <= m) Modify(o << 1, l, m, ll, rr, v);
      if (rr > m) Modify(o << 1 | 1, m + 1, r, ll, rr, v);
      Pull(o);
    }

    int QueryMax(int o, int l, int r, int ll, int rr) {
      if (ll <= l && rr >= r) return ma[o];
      Push(o, l, r);
      int m = (l + r) >> 1, ans = 0;
      if (ll <= m) ans = max(ans, QueryMax(o << 1, l, m, ll, rr));
      if (rr > m) ans = max(ans, QueryMax(o << 1 | 1, m + 1, r, ll, rr));
      return ans;
    }

    long long QuerySum(int o, int l, int r, int ll, int rr) {
      if (ll <= l && rr >= r) return sum[o];
      Push(o, l, r);
      int m = (l + r) >> 1;
      long long ans = 0;
      if (ll <= m) ans += QuerySum(o << 1, l, m, ll, rr);
      if (rr > m) ans += QuerySum(o << 1 | 1, m + 1, r, ll, rr);
      return ans;
    }
};

seg_tree sgt;

int main() {
  int t; Read(t);
  for (int cas = 1; cas <= t; ++cas) {
    int n, m; Read(n); Read(m);
    sgt.Build(1, 1, n);
    for (int i = 0, op, l, r, v; i < m; ++i) {
      Read(op); Read(l); Read(r);
      if (op == 0) {
        Read(v);
        sgt.Modify(1, 1, n, l, r, v);
      }
      else if (op == 1) printf("%d\n", sgt.QueryMax(1, 1, n, l, r));
      else printf("%lld\n", sgt.QuerySum(1, 1, n, l, r));
    }
  }
  return 0;
}

