#include <bits/stdc++.h>

const int N = 1e6 + 5;

char ch[N * 4];
struct Node {
    int min, max, sum;
};
Node tree[N * 4];

Node Unite(const Node &k1, const Node &k2) {
    Node ret;
    ret.sum = k1.sum + k2.sum;
    ret.min = std::min({k1.min, k1.sum + k2.min, k1.sum + k2.sum});
    ret.max = std::max({k1.max, k1.sum + k2.max, k1.sum + k2.sum});
    return ret;
}

void Pull(int o) {
    tree[o] = Unite(tree[o * 2], tree[o * 2 + 1]);
}

void Build(int o, int l, int r) {
    if (l == r) {
        ch[o] = ' ';
        return;
    }
    int m = (l + r) / 2;
    Build(o * 2, l, m);
    Build(o * 2 + 1, m + 1, r);
    Pull(o);
}

void Modify(int o, int l, int r, int idx, char c) {
    if (l == r) {
        ch[o] = c;
        if (ch[o] == '(') {
            tree[o].sum = 1;
        }
        else if (ch[o] == ')') {
            tree[o].sum = -1;
        }
        else {
            tree[o].sum = 0;
        }
        tree[o].min = tree[o].max = tree[o].sum;
        return;
    }
    int m = (l + r) / 2;
    if (idx <= m) {
        Modify(o * 2, l, m, idx, c);
    }
    else {
        Modify(o * 2 + 1, m + 1, r, idx, c);
    }
    Pull(o);
}

Node Query(int o, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
        return tree[o];
    }
    int m = (l + r) / 2;
    if (ql <= m && qr > m) {
        return Unite(Query(o * 2, l, m, ql, qr), Query(o * 2 + 1, m + 1, r, ql, qr));
    }
    else if (ql <= m) {
        return Query(o * 2, l, m, ql, qr);
    }
    else {
        return Query(o * 2 + 1, m + 1, r, ql, qr);
    }
}

int n, idx, len;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    std::cin.get();
    std::getline(std::cin, s);
    idx = len = 1;
    Build(1, 1, n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            if (idx >= 2) {
                --idx;
            }
        }
        else if (s[i] == 'R') {
            ++idx;
        }
        else {
            Modify(1, 1, n, idx, s[i]);
        }
        len = std::max(len, idx);
        Node qry = Query(1, 1, n, 1, len);
        if (qry.min < 0 || qry.sum != 0) {
            std::cout << -1 << ' ';
        }
        else {
            std::cout << qry.max << ' ';
        }
    }
    std::cout << '\n';
    return 0;
}