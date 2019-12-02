#include <bits/stdc++.h>

const int N = 1e5 + 5;
const int C = 4;
const int P[C] =  {2, 3, 5, 7};

struct Node {
    int max, cnt[C];
};
Node tree[N * 4], lazy[N * 4];

Node Unite(const Node &k1, const Node &k2) {
    Node ret = {0, {0}};
    for (int i = 0; i < C; ++i) {
        ret.cnt[i] = std::max(k1.cnt[i], k2.cnt[i]);
        ret.max = std::max(ret.max, ret.cnt[i]);
    }
    return ret;
}

void Pull(int o) {
    tree[o] = Unite(tree[o * 2], tree[o * 2 + 1]);
}

void Push(int o) {
    if (lazy[o].max != 0) {
        lazy[o * 2].max = lazy[o * 2 + 1].max = 1;
        for (int i = 0; i < C; ++i) {
            tree[o * 2].cnt[i] += lazy[o].cnt[i];
            tree[o * 2].max = std::max(tree[o * 2].max, tree[o * 2].cnt[i]);
            tree[o * 2 + 1].cnt[i] += lazy[o].cnt[i];
            tree[o * 2 + 1].max = std::max(tree[o * 2 + 1].max, tree[o * 2 + 1].cnt[i]);
            lazy[o * 2].cnt[i] += lazy[o].cnt[i];
            lazy[o * 2 + 1].cnt[i] += lazy[o].cnt[i];
        }
        lazy[o].max = 0;
        for (int i = 0; i < C; ++i) {
            lazy[o].cnt[i] = 0;
        }
    }
}

void Build(int o, int l, int r) {
    lazy[o].max = 0;
    for (int i = 0; i < C; ++i) {
        lazy[o].cnt[i] = 0;
    }
    if (l == r) {
        tree[o].max = 0;
        for (int i = 0; i < C; ++i) {
            tree[o].cnt[i] = 0;
        }
        return;
    }
    int m = (l + r) / 2;
    Build(o * 2, l, m);
    Build(o * 2 + 1, m + 1, r);
    Pull(o);
}

void Modify(int o, int l, int r, int ql, int qr, const std::vector<std::pair<int, int>> &factor) {
    if (ql <= l && qr >= r) {
        for (auto &pr : factor) {
            tree[o].cnt[pr.first] += pr.second;
            tree[o].max = std::max(tree[o].max, tree[o].cnt[pr.first]);
            lazy[o].max = 1;
            lazy[o].cnt[pr.first] += pr.second;
        }
        return;
    }
    Push(o);
    int m = (l + r) / 2;
    if (ql <= m) {
        Modify(o * 2, l, m, ql, qr, factor);
    }
    if (qr > m) {
        Modify(o * 2 + 1, m + 1, r, ql, qr, factor);
    }
    Pull(o);
}

int Query(int o, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
        return tree[o].max;
    }
    Push(o);
    int m = (l + r) / 2, ret = 0;
    if (ql <= m) {
        ret = std::max(ret, Query(o * 2, l, m, ql, qr));
    }
    if (qr > m) {
        ret = std::max(ret, Query(o * 2 + 1, m + 1, r, ql, qr));
    }
    return ret;
}

int n, q, l, r, x;
char opt[10];

std::vector<std::pair<int, int>> Div(int x) {
    std::vector<std::pair<int, int>> ret;
    return ret;
}

int main() {
    scanf("%d%d", &n, &q);
    Build(1, 1, n);
    while (q--) {
        scanf("%s", opt);
        if (std::strcmp(opt, "MULTIPLY") == 0) {
            scanf("%d%d%d", &l, &r, &x);
            std::vector<std::pair<int, int>> factor;
            for (int i = 0; i < C; ++i) {
                int cnt = 0;
                while (x % P[i] == 0) {
                    ++cnt;
                    x /= P[i];
                }
                factor.push_back({i, cnt});
            }
            Modify(1, 1, n, l, r, factor);
        }
        else {
            scanf("%d%d", &l, &r);
            printf("ANSWER %d\n", Query(1, 1, n, l, r));
        }
    }
    return 0;
}