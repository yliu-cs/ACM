#include <bits/stdc++.h>

const int MAXN = 200005;
const int M = MAXN * 100;
int n,q,tot;
int a[MAXN];
int T[MAXN],lson[M],rson[M],c[M];
int mp[MAXN];
int build(int l,int r){
    int root = tot++;
    c[root] = 0;
    if(l != r){
        int mid = (l+r)>>1;
        lson[root] = build(l,mid);
        rson[root] = build(mid+1,r);
    }
    return root;
}
int update(int root, int pos, int val) {
    int newroot = tot++, tmp = newroot;
    c[newroot] = c[root] + val;
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            lson[newroot] = tot++;
            rson[newroot] = rson[root];
            newroot = lson[newroot];
            root = lson[root];
            r = mid;
        }
        else {
            rson[newroot] = tot++;
            lson[newroot] = lson[root];
            newroot = rson[newroot];
            root = rson[root];
            l = mid + 1;
        }
        c[newroot] = c[root] + val;
    }
    return tmp;
}

int query(int root, int pos) {
    int ret = 0;
    int l = 1, r = n;
    while (pos < r) {
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            r = mid;
            root = lson[root];
        }
        else {
            ret += c[lson[root]];
            root = rson[root];
            l = mid + 1;
        }
    }
    return ret + c[root];
}

int main(int argc, char *argv[]) {
    while (~scanf("%d%d", &n, &q)) {
        tot = 0;
        memset(mp, -1, sizeof(mp));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            a[n + i] = a[i];
        }
        n <<= 1;
        T[n + 1] = build(1, n);
        for (int i = n; i >= 1; --i) {
            if (mp[a[i]] == -1) {
                T[i] = update(T[i + 1], i, 1);
            }
            else {
                int tmp = update(T[i + 1], mp[a[i]], -1);
                T[i] = update(tmp, i, 1);
            }
            mp[a[i]] = i;
        }
        while (q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            l += n / 2;
            std::swap(l, r);
            printf("%d\n", query(T[l], r));
        }
    }
    return 0;
}

