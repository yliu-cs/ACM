#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int maxm = 1e5 + 5;
struct SegTree {
    int n;
    int tree[maxn * 4];
    void Pull(int o) {
        tree[o] = tree[o * 2] + tree[o * 2 + 1];
    }
    void Build(int o, int l, int r) {
        tree[o] = 0;
        if (l == r) return;
        int m = (l + r) / 2;
        Build(o * 2, l, m);
        Build(o * 2 + 1, m + 1, r);
        Pull(o);
    }
    void Init(int _n) {
        n = _n;
        Build(1, 1, n);
    }
    void Modify(int o, int l, int r, int idx) {
        if (l == r) {
            ++tree[o];
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m) Modify(o * 2, l, m, idx);
        else Modify(o * 2 + 1, m + 1, r, idx);
        Pull(o);
    }
    void Modify(int idx) { Modify(1, 1, n, idx); }
    int Query(int o, int l, int r, int ll, int rr) {
        if (ll <= l && rr >= r) return tree[o];
        int m = (l + r) / 2, ret = 0;
        if (ll <= m) ret += Query(o * 2, l, m, ll, rr);
        if (rr > m) ret += Query(o * 2 + 1, m + 1, r, ll, rr);
        return ret;
    }
    int Query(int ll, int rr) { return Query(1, 1, n, ll, rr); }
};
int n, m;
int a[maxn], pos[maxn];
struct Query { int l, r, id; };
Query qry[maxm];
std::vector<int> add[maxn];
SegTree T;
int ans[maxn];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        pos[a[i]] = i;
    }
    for (int x = 1; x <= n; ++x) {
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                if (i != x) add[std::max(pos[i], pos[x])].push_back(std::min(pos[i], pos[x]));
                if (i * i != x && x / i != x) add[std::max(pos[x / i], pos[x])].push_back(std::min(pos[x / i], pos[x]));
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> qry[i].l >> qry[i].r;
        qry[i].id = i;
    }
    std::sort(qry + 1, qry + m + 1, [&](Query k1, Query k2) { return k1.r < k2.r; });
    T.Init(n);
    int idx = 1;
    for (int i = 1; i <= n; ++i) {
        for (auto &l : add[i]) T.Modify(l);
        while (idx <= m && qry[idx].r == i) {
            ans[qry[idx].id] = T.Query(qry[idx].l, qry[idx].r);
            ++idx;
        }
    }
    for (int i = 1; i <= m; ++i) std::cout << ans[i] << '\n';
    return 0;
}