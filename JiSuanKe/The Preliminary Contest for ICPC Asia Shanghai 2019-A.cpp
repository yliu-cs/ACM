#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const long long inf = 1e18 + 5;
int n, m;
struct SaveEdge { int u, v, c; };
SaveEdge edge[maxn];
struct Edge { int v, c; };
std::vector<Edge> g[maxn];
int dfs_clock, fa[maxn], in[maxn], out[maxn], ele[maxn], dep[maxn];
long long dis[maxn];
void DfsSeq(int u, int p, int d_p, long long d_s) {
    fa[u] = p; dis[u] = d_s; dep[u] = d_p;
    in[u] = ++dfs_clock; ele[dfs_clock] = u;
    for (auto &e : g[u]) {
        int v = e.v, c = e.c;
        if (v == p) continue;
        DfsSeq(v, u, d_p + 1, d_s + c);
    }
    out[u] = dfs_clock;
}
long long tree[maxn * 4], lazy[maxn * 4];
void Pull(int o) {
    tree[o] = std::max(tree[o * 2], tree[o * 2 + 1]);
}
void Push(int o) {
    if (lazy[o] != 0) {
        tree[o * 2] += lazy[o];
        tree[o * 2 + 1] += lazy[o];
        lazy[o * 2] += lazy[o];
        lazy[o * 2 + 1] += lazy[o];
        lazy[o] = 0;
    }
}
void Build(int o, int l, int r) {
    tree[o] = lazy[o] = 0;
    if (l == r) {
        tree[o] = dis[ele[l]];
        return;
    }
    int mid = (l + r) / 2;
    Build(o * 2, l, mid);
    Build(o * 2 + 1, mid + 1, r);
    Pull(o);
}
void Modify(int o, int l, int r, int ll, int rr, int v) {
    if (ll <= l && rr >= r) {
        tree[o] += v;
        lazy[o] += v;
        return;
    }
    Push(o);
    int mid = (l + r) / 2;
    if (ll <= mid) Modify(o * 2, l, mid, ll, rr, v);
    if (rr > mid) Modify(o * 2 + 1, mid + 1, r, ll, rr, v);
    Pull(o);
}
void Modify(int ll, int rr, int v) {
    Modify(1, 1, n, ll, rr, v);
}
long long Query(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) return tree[o];
    Push(o);
    int mid = (l + r) / 2;
    long long ret = -inf;
    if (ll <= mid) ret = std::max(ret, Query(o * 2, l, mid, ll, rr));
    if (rr > mid) ret = std::max(ret, Query(o * 2 + 1, mid + 1, r, ll, rr));
    return ret;
}
long long Query(int ll, int rr) {
    if (rr < ll) return 0;
    return Query(1, 1, n, ll, rr);
}
int main() {
    scanf("%d", &n);
    for (int i = 1, u, v, c; i < n; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        g[u].push_back((Edge){v, c});
        g[v].push_back((Edge){u, c});
        edge[i] = (SaveEdge){u, v, c};
    }
    DfsSeq(1, 0, 1, 0);
    Build(1, 1, n);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'C') {
            int e, c;
            scanf("%d%d", &e, &c);
            int u = edge[e].u, v = edge[e].v, lastc = edge[e].c;
            if (dep[u] > dep[v]) std::swap(u, v);
            Modify(in[v], out[v], c - lastc);
            edge[e].c = c;
        }
        else if (op[0] == 'Q') {
            int u;
            scanf("%d", &u);
            long long ori = Query(in[u], in[u]);
            long long ans = Query(in[u], out[u]) - ori;
            int _fa = fa[u], _son = u;
            while (_fa != 0) {
                long long pre = Query(in[_fa], in[_fa]), tmp = std::max(Query(in[_fa], in[_son] - 1), Query(out[_son] + 1, out[_fa]));
                ans = std::max(ans, ori + tmp - 2ll * pre);
                _son = _fa; _fa = fa[_son];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}