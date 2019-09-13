#include <cstdio>
const int maxn = 1e6 + 5;
const int maxdigit = 4;
struct SegTree {
  int n;
  int sum[maxdigit][maxn * 4];
  int lazy[maxdigit][maxn * 4];
  bool rev[maxdigit][maxn * 4];
  void Push(int o, int l, int r, int dgt) {
    int m = (l + r) / 2;
    if (lazy[dgt][o] != -1) {
      int f = lazy[dgt][o];
      if (f) {
        sum[dgt][o * 2] = m - l + 1;
        sum[dgt][o * 2 + 1] = r - m;
        lazy[dgt][o * 2] = lazy[dgt][o * 2 + 1] = 1;
        rev[dgt][o * 2] = rev[dgt][o * 2 + 1] = 0;
      }
      else {
        sum[dgt][o * 2] = sum[dgt][o * 2 + 1] = 0;
        lazy[dgt][o * 2] = lazy[dgt][o * 2 + 1] = 0;
        rev[dgt][o * 2] = rev[dgt][o * 2 + 1] = 0;
      }
      lazy[dgt][o] = -1;
    }
    if (rev[dgt][o] != 0) {
      sum[dgt][o * 2] = m - l + 1 - sum[dgt][o * 2];
      sum[dgt][o * 2 + 1] = r - m - sum[dgt][o * 2 + 1];
      rev[dgt][o * 2] ^= 1;
      rev[dgt][o * 2 + 1] ^= 1;
      rev[dgt][o] = 0;
    }
  }
  void Build(int o, int l, int r, int arr[]) {
    for (int dgt = 0; dgt < maxdigit; ++dgt) {
      lazy[dgt][o] = -1;
      rev[dgt][o] = 0;
    }
    if (l == r) {
      for (int dgt = 0; dgt < maxdigit; ++dgt) sum[dgt][o] = (bool)(arr[l] & (1 << dgt));
      return;
    }
    int m = (l + r) / 2;
    Build(o * 2, l, m, arr);
    Build(o * 2 + 1, m + 1, r, arr);
    for (int dgt = 0; dgt < maxdigit; ++dgt) sum[dgt][o] = sum[dgt][o * 2] + sum[dgt][o * 2 + 1];
  }
  void Init(int _n, int arr[]) {
    n = _n;
    Build(1, 1, n, arr);
  }
  void Modify(int o, int l, int r, int ll, int rr, int dgt, int f) {
    if (ll <= l && rr >= r) {
      if (f == 1) {
        sum[dgt][o] = lazy[dgt][o] = rev[dgt][o] = 0;
      }
      else if (f == 2) {
        sum[dgt][o] = r - l + 1;
        lazy[dgt][o] = 1;
        rev[dgt][o] = 0;
      }
      else if (f == 3) {
        sum[dgt][o] = r - l + 1 - sum[dgt][o];
        rev[dgt][o] ^= 1;
      }
      return;
    }
    Push(o, l, r, dgt);
    int m = (l + r) / 2;
    if (ll <= m) Modify(o * 2, l, m, ll, rr, dgt, f);
    if (rr > m) Modify(o * 2 + 1, m + 1, r, ll, rr, dgt, f);
    sum[dgt][o] = sum[dgt][o * 2] + sum[dgt][o * 2 + 1];
  }
  void Modify(int ll, int rr, int dgt, int f) {
    Modify(1, 1, n, ll, rr, dgt, f);
  }
  int Query(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) {
      int ret = 0;
      for (int dgt = maxdigit - 1; dgt >= 0; --dgt) ret = (ret << 1) + sum[dgt][o];
      return ret;
    }
    for (int dgt = 0; dgt < maxdigit; ++dgt) Push(o, l, r, dgt);
    int m = (l + r) / 2, ret = 0;
    if (ll <= m) ret += Query(o * 2, l, m, ll, rr);
    if (rr > m) ret += Query(o * 2 + 1, m + 1, r, ll, rr);
    return ret;
  }
  int Query(int ll, int rr) {
    return Query(1, 1, n, ll, rr);
  }
};
int t;
int n, m;
int a[maxn];
SegTree tree;
int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    tree.Init(n, a);
    for (int i = 1; i <= m; ++i) {
      char op[4];
      scanf("%s", op);
      if (op[0] == 'S') {
        int l, r;
        scanf("%d%d", &l, &r);
        ++l; ++r;
        printf("%d\n", tree.Query(l, r));
      }
      else if (op[0] == 'A') {
        int opn, l, r;
        scanf("%d%d%d", &opn, &l, &r);
        ++l; ++r;
        for (int dgt = 0; dgt < maxdigit; ++dgt) {
          if (!(opn & (1 << dgt))) tree.Modify(l, r, dgt, 1);
        }
      }
      else if (op[0] == 'O') {
        int opn, l, r;
        scanf("%d%d%d", &opn, &l, &r);
        ++l; ++r;
        for (int dgt = 0; dgt < maxdigit; ++dgt) {
          if (opn & (1 << dgt)) tree.Modify(l, r, dgt, 2);
        }
      }
      else if (op[0] == 'X') {
        int opn, l, r;
        scanf("%d%d%d", &opn, &l, &r);
        ++l; ++r;
        for (int dgt = 0; dgt < maxdigit; ++dgt) {
          if (opn & (1 << dgt)) tree.Modify(l, r, dgt, 3);
        }
      }
    }
  }
  return 0;
}
