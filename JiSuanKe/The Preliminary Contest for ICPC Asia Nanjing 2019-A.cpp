#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
struct SegTree {
    int n;
    long long tree[maxn * 4];
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
    void Modify(int o, int l, int r, int idx, int v) {
        if (l == r) {
            tree[o] += v;
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m) Modify(o * 2, l, m, idx, v);
        else Modify(o * 2 + 1, m + 1, r, idx, v);
        Pull(o);
    }
    void Modify(int idx, long long v) {
        Modify(1, 1, n, idx, v);
    }
    long long Query(int o, int l, int r, int ll, int rr) {
        if (ll <= l && rr >= r) return tree[o];
        int m = (l + r) / 2;
        long long ret = 0;
        if (ll <= m) ret += Query(o * 2, l, m, ll, rr);
        if (rr > m) ret += Query(o * 2 + 1, m + 1, r, ll, rr);
        return ret;
    }
    long long Query(int ll, int rr) {
        return Query(1, 1, n, ll, rr);
    }
};
long long Gao(int x, int y, int n) {
    --x, --y;
    int p = std::min({x, y, n - x - 1, n - y - 1}), q = n - p - 1;
    long long base = (long long)(n) * n - (long long)(n - 2 * p) * (long long)(n - 2 * p) + 1;
    if (x == q) return base + (q - y);
    base += n - 2 * p - 1;
    if (y == p) return base + (q - x);
    base += n - 2 * p - 1;
    if (x == p) return base + (y - p);
    base += n - 2 * p - 1;
    return base + (x - p);
}

int Get(long long x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
SegTree T;
struct query { int l, r, id; };
std::vector<std::pair<int, int>> ele[maxn];
std::vector<query> sub[maxn], add[maxn];
long long ans[maxn];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    for (int cas = 1; cas <= t; ++cas) {
        int n, m, q;
        std::cin >> n >> m >> q;
        for (int i = 0; i < maxn; ++i) ele[i].clear();
        for (int i = 1, x, y; i <= m; ++i) {
            std::cin >> x >> y;
            ele[x].push_back({y, Get(Gao(x, y, n))});
        }
        for (int i = 0; i < maxn; ++i) sub[i].clear(), add[i].clear();
        for (int i = 1, x1, y1, x2, y2; i <= q; ++i) {
            std::cin >> x1 >> y1 >> x2 >> y2;
            sub[x1 - 1].push_back((query){y1, y2, i});
            add[x2].push_back((query){y1, y2, i});
        }
        T.Init(maxn - 1);
        for (int i = 1; i <= q; ++i) ans[i] = 0;
        for (int i = 0; i < maxn; ++i) {
            for (auto &v : ele[i]) T.Modify(v.first, v.second);
            for (auto &v : sub[i]) ans[v.id] -= T.Query(v.l, v.r);
            for (auto &v : add[i]) ans[v.id] += T.Query(v.l, v.r);
        }
        for (int i = 1; i <= q; ++i) std::cout << ans[i] << '\n';
    }
    return 0;
}