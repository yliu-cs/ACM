#include <bits/stdc++.h>
const int maxq = 1e6 + 5;
const int inf = 1e9 + 5;
struct SegTree {
    int n;
    int tree[maxq * 8];
    void Pull(int o) {
        tree[o] = std::min(tree[o * 2], tree[o * 2 + 1]);
    }
    void Build(int o, int l, int r) {
        if (l == r) {
            tree[o] = l;
            return;
        }
        int m = (l + r) / 2;
        Build(o * 2, l, m);
        Build(o * 2 + 1, m + 1, r);
        Pull(o);
    }
    void Init(int _n) {
        n = _n;
        Build(1, 1, n);
    }
    void Modify(int o, int l, int r, int idx) {
        if (l == r) {
            tree[o] = inf;
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m) Modify(o * 2, l, m, idx);
        else Modify(o * 2 + 1, m + 1, r, idx);
        Pull(o);
    }
    void Modify(int idx) { Modify(1, 1, n, idx); }
    int Query(int o, int l, int r, int ll, int rr) {
        if (ll <= l && rr >= r) return tree[o];
        int m = (l + r) / 2, ret = inf;
        if (ll <= m) ret = std::min(ret, Query(o * 2, l, m, ll, rr));
        if (rr > m) ret = std::min(ret, Query(o * 2 + 1, m + 1, r, ll, rr));
        return ret;
    }
    int Query(int ll, int rr) { return Query(1, 1, n, ll, rr); }
};
int n, q;
SegTree T;
struct Query { int opt, x; };
Query qry[maxq];
std::vector<int> x;
int Get(int _x) {
    return std::lower_bound(x.begin(), x.end(), _x) - x.begin() + 1;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> q;
    for (int i = 1, opt, _x; i <= q; ++i) {
        std::cin >> opt >> _x;
        x.push_back(_x);
        x.push_back(_x + 1);
        qry[i] = (Query){opt, _x};
    }
    std::sort(x.begin(), x.end());
    x.erase(std::unique(x.begin(), x.end()), x.end());
    T.Init(x.size());
    for (int i = 1; i <= q; ++i) {
        if (qry[i].opt == 1) T.Modify(Get(qry[i].x));
        else std::cout << x[T.Query(Get(qry[i].x), x.size()) - 1] << '\n';
    }
    return 0;
}