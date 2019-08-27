#include <bits/stdc++.h>
const int maxn = 3e5 + 5;
struct SegTree {
    int n;
    long long cnt[maxn * 4], lazy[maxn * 4];
    void Pull(int o) {
        cnt[o] = cnt[o * 2] + cnt[o * 2 + 1];
    }
    void Push(int o, int l, int r) {
        int m = (l + r) / 2;
        if (lazy[o] != 0) {
            cnt[o * 2] += 1ll * (m - l + 1) * lazy[o];
            cnt[o * 2 + 1] += 1ll * (r - m) * lazy[o];
            lazy[o * 2] += lazy[o];
            lazy[o * 2 + 1] += lazy[o];
            lazy[o] = 0;
        }
    }
    void Build(int o, int l, int r) {
        cnt[o] = lazy[o] = 0;
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
    void Modify(int o, int l, int r, int ll, int rr, long long v) {
        if (ll <= l && rr >= r) {
            cnt[o] += 1ll * (r - l + 1) * v;
            lazy[o] += v;
            return;
        }
        Push(o, l, r);
        int m = (l + r) / 2;
        if (ll <= m) Modify(o * 2, l, m, ll, rr, v);
        if (rr > m) Modify(o * 2 + 1, m + 1, r, ll, rr, v);
        Pull(o);
    }
    void Modify(int ll, int rr, int v) {
        Modify(1, 1, n, ll, rr, v);
    }
    long long Query(int o, int l, int r, int ll, int rr) {
        if (ll <= l && rr >= r) return cnt[o];
        Push(o, l, r);
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
std::vector<int> g[maxn];
int in[maxn], out[maxn], ele[maxn];
int dfs_clock;
void DfsSeq(int u) {
    in[u] = ++dfs_clock;
    ele[dfs_clock] = u;
    for (auto &v : g[u]) DfsSeq(v);
    out[u] = dfs_clock;
}
SegTree T;
int left[maxn], right[maxn];
struct seg { int l, r, id; };
std::vector<seg> sub[maxn], add[maxn];
long long ans[maxn];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        std::cin >> u >> v;
        g[u].push_back(v);
        std::cin >> left[v] >> right[v];
    }
    left[1] = 1; right[1] = n;
    DfsSeq(1);
    int q;
    std::cin >> q;
    for (int i = 1, o, l, r; i <= q; ++i) {
        std::cin >> o >> l >> r;
        sub[in[o] - 1].push_back((seg){l, r, i});
        add[out[o]].push_back((seg){l, r, i});
    }
    T.Init(n);
    for (int i = 1; i <= m + 1; ++i) {
        T.Modify(left[ele[i]], right[ele[i]], 1);
        for (auto &v : sub[i]) ans[v.id] -= T.Query(v.l, v.r);
        for (auto &v : add[i]) ans[v.id] += T.Query(v.l, v.r);
    }
    for (int i = 1; i <= q; ++i) std::cout << ans[i] << '\n';
    return 0;
}