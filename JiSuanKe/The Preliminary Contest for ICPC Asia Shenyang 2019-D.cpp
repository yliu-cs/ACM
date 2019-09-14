#include <bits/stdc++.h>
const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;
int n;
struct Edge { int v; long long c; };
std::vector<Edge> g[maxn];
int sum, rt;
int son[maxn], sz[maxn];
bool vis[maxn];
void FindRoot(int u, int p) {
    sz[u] = 1; son[u] = 0;
    for (auto &e : g[u]) {
        int v = e.v;
        if (v == p || vis[v]) continue;
        FindRoot(v, u);
        sz[u] += sz[v];
        son[u] = std::max(son[u], sz[v]);
    }
    son[u] = std::max(son[u], sum - son[u]);
    if (son[u] < son[rt]) rt = u;
}
long long ans[3];
long long dis[maxn];
std::vector<long long> edge[3];
void GetCnt(int u, int p) {
    edge[dis[u] % 3].emplace_back(dis[u]);
    for (auto &e : g[u]) {
        int v = e.v;
        long long c = e.c;
        if (v == p || vis[v]) continue;
        dis[v] = dis[u] + c;
        GetCnt(v, u);
    }
}
void Cal(int u, long long c, bool f) {
    dis[u] = c;
    for (int i = 0; i < 3; ++i) edge[i].clear();
    GetCnt(u, 0);
    long long sz0 = edge[0].size(), sz1 = edge[1].size(), sz2 = edge[2].size();
    if (f) {
        for (auto &i : edge[0]) {
            ans[0] = (ans[0] + i * sz0 % mod) % mod;
            ans[1] = (ans[1] + i * sz1 % mod) % mod;
            ans[2] = (ans[2] + i * sz2 % mod) % mod;
        }
        for (auto &i : edge[1]) {
            ans[0] = (ans[0] + i * sz2 % mod) % mod;
            ans[1] = (ans[1] + i * sz0 % mod) % mod;
            ans[2] = (ans[2] + i * sz1 % mod) % mod;
        }
        for (auto &i : edge[2]) {
            ans[0] = (ans[0] + i * sz1 % mod) % mod;
            ans[1] = (ans[1] + i * sz2 % mod) % mod;
            ans[2] = (ans[2] + i * sz0 % mod) % mod;
        }
    }
    else {
        for (auto &i : edge[0]) {
            ans[0] = (ans[0] - i * sz0 % mod + mod) % mod;
            ans[1] = (ans[1] - i * sz1 % mod + mod) % mod;
            ans[2] = (ans[2] - i * sz2 % mod + mod) % mod;
        }
        for (auto &i : edge[1]) {
            ans[0] = (ans[0] - i * sz2 % mod + mod) % mod;
            ans[1] = (ans[1] - i * sz0 % mod + mod) % mod;
            ans[2] = (ans[2] - i * sz1 % mod + mod) % mod;
        }
        for (auto &i : edge[2]) {
            ans[0] = (ans[0] - i * sz1 % mod + mod) % mod;
            ans[1] = (ans[1] - i * sz2 % mod + mod) % mod;
            ans[2] = (ans[2] - i * sz0 % mod + mod) % mod;
        }
    }
}
void Dfs(int u) {
    Cal(u, 0, true);
    vis[u] = true;
    for (auto &e : g[u]) {
        int v = e.v;
        long long c = e.c;
        if (vis[v]) continue;
        Cal(v, c, false);
        rt = 0;
        sum = sz[v];
        son[rt] = n;
        FindRoot(v, u);
        Dfs(rt);
    }
}
int main() {
    while (~scanf("%d", &n)) {
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1, u, v, c; i < n; ++i) {
            scanf("%d%d%d", &u, &v, &c);
            ++u; ++v;
            g[u].push_back((Edge){v, c});
            g[v].push_back((Edge){u, c});
        }
        rt = 0;
        sum = son[rt] = n;
        memset(vis, false, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        memset(ans, 0, sizeof(ans));
        FindRoot(1, 0);
        Dfs(1);
        for (int i = 0; i < 3; ++i) ans[i] = (ans[i] * 2) % mod;
        printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
    }
    return 0;
}
