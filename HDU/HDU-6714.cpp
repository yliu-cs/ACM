#include <bits/stdc++.h>
const int maxn = 1e3 + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long mod = 998244353;
int n, m;
struct edge { int v; long long c; };
std::vector<edge> g[maxn];
struct node {
    int u, max;
    long long w;
    bool operator < (const node &k) const {
        if (w == k.w) return max > k.max;
        return w > k.w;
    }
};
long long dis[maxn], max[maxn];
long long Dijkstra(int s) {
    std::priority_queue<node> que;
    memset(max, inf, sizeof(max));
    memset(dis, inf, sizeof(dis));
    long long ret = 0;
    for (auto &e : g[s]) {
        que.push((node){e.v, e.v, e.c});
        dis[e.v] = std::min(dis[e.v], e.c);
        max[e.v] = 0;
    }
    while (!que.empty()) {
        node cur = que.top(); que.pop();
        int u = cur.u, mx = cur.max;
        long long w = cur.w;
        for (auto &e : g[u]) {
            int v = e.v, c = e.c;
            if (v == s) continue;
            if (w + e.c < dis[v] || (w + e.c == dis[v] && std::max(mx, u) < max[v])) {
                que.push((node){v, std::max(mx, u), w + e.c});
                dis[v] = w + e.c;
                if (max[v] != inf) ret = (ret - max[v] + mod) % mod;
                max[v] = std::max(mx, u);
                ret = (ret + max[v]) % mod;
            }
        }
    }
    return (ret + mod) % mod;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1, u, v, c; i <= m; ++i) {
            std::cin >> u >> v >> c;
            if (u == v) continue;
            g[u].push_back((edge){v, c});
            g[v].push_back((edge){u, c});
        }
        long long ans = 0;
        for (int i = 1; i <= n; ++i) ans = (ans + Dijkstra(i)) % mod;
        std::cout << (ans + mod) % mod << '\n';
    }
    return 0;
}
