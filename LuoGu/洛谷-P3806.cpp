#include <bits/stdc++.h>
const int maxn = 1e4 + 5;
const int maxk = 1e7 + 5;
int n, m;
struct Edge { int v, c; };
std::vector<Edge> g[maxn];
int sum, rt;
int max[maxn], sz[maxn];
bool vis[maxn];
void FindRoot(int u, int p) {
    sz[u] = 1; max[u] = 0;
    for (auto &e : g[u]) {
        int v = e.v;
        if (v == p || vis[v]) continue;
        FindRoot(v, u);
        sz[u] += sz[v];
        max[u] = std::max(max[u], sz[v]);
    }
    max[u] = std::max(max[u], sum - max[u]);
    if (max[u] < max[rt]) rt = u;
}
int diset[maxk];
int tot;
int check[maxk], dis[maxn];
void Cal(int u, int p, int len) {
    diset[tot++] = dis[u];
    for (auto &e : g[u]) {
        int v = e.v, c = e.c;
        if (v == p || vis[v]) continue;
        dis[v] = len + c;
        Cal(v, u, len + c);
    }
}
void Solve(int u, int len, int c) {
    tot = 0;
    dis[u] = len;
    Cal(u, 0, len);
    for (int i = 0; i < tot; ++i) {
        for (int j = 0; j < tot; ++j) {
            if (i == j) continue;
            check[diset[i] + diset[j]] += c;
        }
    }
}
void Dfs(int u) {
    Solve(u, 0, 1);
    vis[u] = true;
    for (auto &e : g[u]) {
        int v = e.v, c = e.c;
        if (vis[v]) continue;
        Solve(v, c, -1);
        rt = 0;
        sum = sz[v];
        max[rt] = n;
        FindRoot(v, u);
        Dfs(rt);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1, u, v, c; i < n; ++i) {
        std::cin >> u >> v >> c;
        g[u].push_back((Edge){v, c});
        g[v].push_back((Edge){u, c});
    }
    rt = 0;
    sum = max[rt] = n;
    FindRoot(1, 0);
    Dfs(rt);
    for (int i = 1, k; i <= m; ++i) {
        std::cin >> k;
        if (check[k] != 0) std::cout << "AYE" << '\n';
        else std::cout << "NAY" << '\n';
    }
    return 0;
}