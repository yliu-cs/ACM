#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
struct SegTree {
    int n;
    int max[maxn * 4], lazy[maxn * 4], pos[maxn * 4];
    void Pull(int o) {
        max[o] = std::max(max[o * 2], max[o * 2 + 1]);
        pos[o] = max[o * 2] >= max[o * 2 + 1] ? pos[o * 2] : pos[o * 2 + 1];
    }
    void Push(int o) {
        if (lazy[o] != 0) {
            max[o * 2] += lazy[o];
            max[o * 2 + 1] += lazy[o];
            lazy[o * 2] += lazy[o];
            lazy[o * 2 + 1] += lazy[o];
            lazy[o] = 0;
        }
    }
    void Build(int o, int l, int r) {
        max[o] = lazy[o] = 0; pos[o] = l;
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
    void Modify(int o, int l, int r, int ll, int rr, int v) {
        if (ll <= l && rr >= r) {
            max[o] += v;
            lazy[o] += v;
            return;
        }
        Push(o);
        int m = (l + r) / 2;
        if (ll <= m) Modify(o * 2, l, m, ll, rr, v);
        if (rr > m) Modify(o * 2 + 1, m + 1, r, ll, rr, v);
        Pull(o);
    }
    void Modify(int ll, int rr, int v) {
        Modify(1, 1, n, ll, rr, v);
    }
    int Query(int o, int l, int r, int ll, int rr, int v) {
        if (ll <= l && rr >= r) {
            if (max[o] == v) return pos[o];
            else return rr + 1;
        }
        Push(o);
        int m = (l + r) / 2;
        if (max[o * 2] == v) return pos[o * 2];
        else if (max[o * 2 + 1] == v) return pos[o * 2 + 1];
        else return rr + 1;
        Push(o);
    }
    int Query(int ll, int rr, int v) {
        return Query(1, 1, n, ll, rr, v);
    }
};
SegTree T;
std::vector<int> pos[maxn];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, c, k;
    while (std::cin >> n >> c >> k) {
        for (int i = 1; i <= c; ++i) {
            pos[i].clear();
            pos[i].push_back(0);
        }
        T.Init(n);
        int ans = 0;
        for (int r = 1, x; r <= n; ++r) {
            std::cin >> x;
            T.Modify(r, r, c - 1);
            if (pos[x].back() + 1 <= r - 1) T.Modify(pos[x].back() + 1, r - 1, -1);
            pos[x].push_back(r);
            if (pos[x].size() > k) {
                int idx = pos[x].size() - k - 1;
                T.Modify(pos[x][idx] + 1, pos[x][idx + 1], 1);
            }
            ans = std::max(ans, r - T.Query(1, r, c) + 1);
        }
        std::cout << ans << '\n';
    }
    return 0;
}