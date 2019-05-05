const int maxn = "Edit";

// 动态莫队算法求区间不同数字数量（支持单点修改）
struct MoCap {
  int n, m;
  int block;
  int arr[maxn];
  struct query { int l, r, pre, id; };
  int q_tot;
  query q[maxn];
  struct change { int pos, val; };
  int c_tot;
  change c[maxn];
  int cnt[maxn << 7];
  int cur;
  int ans[maxn];

  void Add(int x) { cur += (++cnt[arr[x]] == 1); }

  void Del(int x) { cur -= (--cnt[arr[x]] == 0); }

  void Modify(int x, int i) {
    if (c[x].pos >= q[i].l && c[x].pos <= q[i].r) {
      cur -= (--cnt[arr[c[x].pos]] == 0);
      cur += (++cnt[c[x].val] == 1);
    }
    std::swap(c[x].val, arr[c[x].pos]);
  }

  void Solve() {
    scanf("%d%d", &n, &m);
    block = (int)sqrt(n);
    for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
    for (int i = 1; i <= m; ++i) {
      char op; getchar();
      scanf("%c", &op);
      if (op == 'Q') {
        int l, r; scanf("%d%d", &l, &r);
        q[++q_tot] = (query){l, r, c_tot, q_tot};
      }
      else {
        int p, v; scanf("%d%d", &p, &v);
        c[++c_tot] = (change){p, v};
      }
    }
    std::sort(q + 1, q + q_tot + 1, [&](query k1, query k2) {
      if ((k1.l / block) == k2.l / block) {
        if ((k1.r / block) == (k2.r / block)) return k1.pre < k2.pre;
        return k1.r < k2.r;
      }
      return k1.l < k2.l;
    });

    int l = 1, r = 0, t = 0;
    for (int i = 1; i <= q_tot; ++i) {
      while (l < q[i].l) Del(l++);
      while (l > q[i].l) Add(--l);
      while (r < q[i].r) Add(++r);
      while (r > q[i].r) Del(r--);
      while (t < q[i].pre) Modify(++t, i);
      while (t > q[i].pre) Modify(t--, i);
      ans[q[i].id] = cur;
    }

    for (int i = 1; i <= q_tot; ++i) printf("%d\n", ans[i]);
  }
}mo;

