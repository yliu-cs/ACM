#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int maxm = 1e5 + 5;
const int maxb = (1 << 21) + 5;
int n, m;
int block;
int a[maxn], b[maxn];
struct Query { int l, r, t, id; };
Query qry[maxm];
int upd[maxm];
int qrytot, updtot;
long long cur;
long long cnt[maxb];
long long ans[maxm];
void Add(int idx) { cur += cnt[b[idx]]++; }
void Sub(int idx) { cur -= --cnt[b[idx]]; }
void Modify(int t, int i) {
    if (upd[t] >= qry[i].l && upd[t] <= qry[i].r) Sub(upd[t]);
    b[upd[t]] ^= a[upd[t]];
    std::swap(a[upd[t]], a[upd[t] + 1]);
    b[upd[t]] ^= a[upd[t]];
    if (upd[t] >= qry[i].l && upd[t] <= qry[i].r) Add(upd[t]);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (std::cin >> n >> m) {
        block = std::pow(n, 2. / 3);
        qrytot = updtot = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            b[i] = b[i - 1] ^ a[i];
        }
        for (int i = 1, opt, l, r, p; i <= m; ++i) {
            std::cin >> opt;
            if (opt == 1) {
                std::cin >> l >> r;
                qry[++qrytot] = (Query) {l - 1, r, updtot, qrytot};
            } else if (opt == 2) {
                std::cin >> p;
                upd[++updtot] = p;
            }
        }
        std::sort(qry + 1, qry + qrytot + 1, [&] (const Query &k1, const Query &k2) {
            if (k1.l / block != k2.l / block) return k1.l < k2.l;
            if (k1.r / block != k2.r / block) return k1.r < k2.r;
            return k1.t < k2.t;
        });
        cur = 0;
        int l = 0, r = -1, t = 0;
        for (int i = 1; i <= qrytot; ++i) {
            while (l < qry[i].l) Sub(l++);
            while (l > qry[i].l) Add(--l);
            while (r < qry[i].r) Add(++r);
            while (r > qry[i].r) Sub(r--);
            while (t < qry[i].t) Modify(++t, i);
            while (t > qry[i].t) Modify(t--, i);
            ans[qry[i].id] = 1ll * (r - l + 1) * (r - l) / 2 - cur;
        }
        for (int i = 1; i <= qrytot; ++i) std::cout << ans[i] << '\n';
    }
    return 0;
}