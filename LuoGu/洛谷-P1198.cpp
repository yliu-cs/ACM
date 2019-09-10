#include <bits/stdc++.h>
const int maxm = 2e5 + 5;
struct SegTree {
    int max[maxm * 4];
    void Modify(int o, int l, int r, int idx, int v) {
        if (l == r) {
            max[o] = v;
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m) Modify(o * 2, l, m, idx, v);
        else Modify(o * 2 + 1, m + 1, r, idx, v);
        max[o] = std::max(max[o * 2], max[o * 2 + 1]);
    }
    int Query(int o, int l, int r, int ll, int rr) {
        if (ll <= l && rr >= r) return max[o];
        int m = (l + r) / 2, ret = 0;
        if (ll <= m) ret = std::max(ret, Query(o * 2, l, m, ll, rr));
        if (rr > m) ret = std::max(ret, Query(o * 2 + 1, m + 1, r, ll, rr));
        return ret;
    }
};
SegTree T;
int main() {
    int m, d;
    scanf("%d%d", &m, &d);
    char op[2];
    int t = 0, len = 0;
    for (int i = 1; i <= m; ++i) {
        scanf("%s", op);
        if (op[0] == 'A') {
            int n;
            scanf("%d", &n);
            ++len;
            T.Modify(1, 1, maxm, len, (n + t) % d);
        }
        else if (op[0] == 'Q') {
            int l;
            scanf("%d", &l);
            t = T.Query(1, 1, maxm, len - l + 1, len);
            printf("%d\n", t);
        }
    }
    return 0;
}
