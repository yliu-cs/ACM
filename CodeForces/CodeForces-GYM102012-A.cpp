#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

struct Edge {
    int u, v;
    unsigned long long weight;

    bool operator < (const Edge &b) const {
        return weight < b.weight;
    }
};

int pre[maxn];
bool vis[maxn];
Edge edges[maxn];

unsigned long long k1, k2;

unsigned long long xorShift128Plus() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

int n, m, u[maxn], v[maxn];
unsigned long long w[maxn];

void init() {
    for (int i = 0; i <= n; ++i) {
        pre[i] = i;
        vis[i] = false;
    }
}

int find(int x) {
    int r = x;
    while (pre[r] != r) {
        r = pre[r];
    }
    int i = x, j;
    while (i != r) {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

void join(int x, int y) {
    int xx = find(x);
    int yy = find(y);
    if (xx != yy) {
        pre[xx] = yy;
    }
}

unsigned long long kruskal() {
    sort(edges + 1, edges + m + 1);
    init();
    unsigned long long ans = 0;
    for (int i = 1; i <= m; ++i) {
        if (find(edges[i].u) != find(edges[i].v)) {
            join(edges[i].u, edges[i].v);
            ans = (ans + edges[i].weight) % mod;
            vis[edges[i].u] = true;
            vis[edges[i].v] = true;
        }
    }
    return ans;
}

void gen() {
    scanf("%d%d%llu%llu", &n, &m, &k1, &k2);
    for (int i = 1; i <= m; ++i) {
        u[i] = xorShift128Plus() % n + 1;
        v[i] = xorShift128Plus() % n + 1;
        w[i] = xorShift128Plus();
        edges[i] = Edge {u[i], v[i], w[i]};
    }
}

bool check() {
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            return false;
        }
    }
    return true;
}

int t;
unsigned long long ans;

int main(int argc, char *argv[]) {
    scanf("%d", &t);
    while (t--) {
        gen();
        ans = kruskal();
        printf("%llu\n", check() ? ans : 0);
    }
    return 0;
}

