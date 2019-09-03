#include <bits/stdc++.h>
const int maxn = 2e4 + 5;
struct Edge { int v, c; };
std::vector<Edge> g[maxn];
int n;
int sum, rt;
int sz[maxn], son[maxn];
bool vis[maxn];
void FindRoot(int u, int p) {
    sz[u] = 1;
    son[u] = 0;
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
int ans;
int dis[maxn], cnt[3];
void GetCnt(int u, int p) {
    ++cnt[dis[u]];
    for (auto &e : g[u]) {
        int v = e.v, c = e.c;
        if (v == p || vis[v]) continue;
        dis[v] = (dis[u] + c) % 3;
        GetCnt(v, u);
    }
}
int Cal(int u, int c) {
    dis[u] = c % 3;
    memset(cnt, 0, sizeof(cnt));
    GetCnt(u, 0);
    return cnt[1] * cnt[2] * 2 + cnt[0] * cnt[0];
}
void Dfs(int u) {
    ans += Cal(u, 0);
    vis[u] = true;
    for (auto &e : g[u]) {
        int v = e.v, c = e.c;
        if (vis[v]) continue;
        ans -= Cal(v, c);
        rt = 0;
        sum = sz[v];
        son[rt] = n;
        FindRoot(v, u);
        Dfs(rt);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1, u, v, c; i < n; ++i) {
        std::cin >> u >> v >> c;
        g[u].push_back((Edge){v, c});
        g[v].push_back((Edge){u, c});
    }
    rt = 0;
    sum = son[rt] = n;
    FindRoot(1, 0);
    Dfs(1);
    int gcd = std::__gcd(n * n, ans);
    std::cout << ans / gcd << '/' << n * n / gcd << '\n';
    return 0;
}