const int maxn = "Edit";

// 静态莫队算法求区间不同数字数量
class MoCap {
  public:
    int n, m;
    int block;
    int arr[maxn];
    struct query {int l, r, id;};
    query q[maxn];
    int cnt[maxn << 1];
    int cur;
    int ans[maxn];

    void Add(int x) {
      cur += (++cnt[arr[x]] == 1);
    }

    void Del(int x) {
      cur -= (--cnt[arr[x]] == 0);
    }

    void Solve() {
      scanf("%d%d", &n, &m);
      block = (int)sqrt(n);
      for (int i = 1; i <= n; ++i) scanf("%d%d", &arr[i]);
      for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
      }
      std::sort(q + 1, q + m + 1, [&](query k1, query k2) {
        return (k1.l / block) == (k2.l / block) ? k1.r < k2.r : k1.l < k2.l;
      });

      int l = 0, r = 0;
      for (int i = 1; i <= m; ++i) {
        while (l < q[i].l) Del(l++);
        while (l > q[i].l) Add(--l);
        while (r < q[i].r) Add(++r);
        while (r > q[i].r) Del(r--);
        ans[q[i].id] = cur;
      }

      for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
    }
}mo;

