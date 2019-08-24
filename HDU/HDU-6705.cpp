#include <bits/stdc++.h>
const int maxn = 5e4 + 5;
struct edge {
    int v, c;
    bool operator < (const edge &k) {
        return c < k.c;
    }
};
std::vector<edge> g[maxn];
struct node {
    int u;
    long long sum;
    bool operator > (const node &k) const {
        return sum > k.sum;
    }
};
struct query {
    int k, id;
    bool operator < (const query &key) {
        return k < key.k;
    }
};
query qry[maxn];
long long ans[maxn];
int main() {
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; ++i) g[i].clear();
        std::priority_queue<node, std::vector<node>, std::greater<node> > que;
        std::multiset<long long> set;
        for (int i = 1, u, v, c; i <= m; ++i) {
            scanf("%d%d%d", &u, &v, &c);
            g[u].push_back((edge){v, c});
            que.push((node){v, c});
            set.insert(c);
        }
        for (int i = 1; i <= n; ++i) std::sort(g[i].begin(), g[i].end());
        long long maxk = 0;
        for (int i = 1, k; i <= q; ++i) {
            scanf("%d", &k);
            maxk = std::max(maxk, 1ll * k);
            qry[i] = (query){k, i};
        }
        while (!que.empty()) {
            auto cur = que.top(); que.pop();
            for (auto &e : g[cur.u]) {
                auto it = set.end(); --it;
                if (set.size() < maxk) {
                    que.push((node){e.v, cur.sum + e.c});
                    set.insert(cur.sum + e.c);
                }
                else if (cur.sum + e.c < *it) {
                    que.push((node){e.v, cur.sum + e.c});
                    set.erase(it);
                    set.insert(cur.sum + e.c);
                }
                else break;
            }
        }
        std::sort(qry + 1, qry + q + 1);
        int k_cnt = 0, idx = 1;
        for (auto &v : set) {
            ++k_cnt;
            while (k_cnt == qry[idx].k && idx <= q) {
                ans[qry[idx].id] = v;
                ++idx;
            }
        }
        for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
    }
    return 0;
}
