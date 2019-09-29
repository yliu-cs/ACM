#include <bits/stdc++.h>
typedef long long ll;
const int maxn = 1e5 + 5;

struct FuncSegTree {
	int tot;
	int rt[maxn];
	int lson[maxn << 5], rson[maxn << 5];
	int cnt[maxn << 5];

	int Build(int l, int r) {
		int o = ++tot, m = (l + r) >> 1;
		cnt[o] = 0;
		if (l != r) {
			lson[o] = Build(l, m);
			rson[o] = Build(m + 1, r);
		}
		return o;
	}

	void Init(int n) {
		tot = 0;
		rt[0] = Build(1, n);
	}

	int Modify(int prev, int l, int r, int v) {
		int o = ++tot, m = (l + r) >> 1;
		lson[o] = lson[prev];
		rson[o] = rson[prev];
		cnt[o] = cnt[prev] + 1;
		if (l != r) {
			if (v <= m) lson[o] = Modify(lson[o], l, m, v);
			else rson[o] = Modify(rson[o], m + 1, r, v);
		}
		return o;
	}

	int Query(int u, int v, int l, int r, int k) {
		if (l == r) return l;
		int m = (l + r) >> 1;
		int num = cnt[lson[v]] - cnt[lson[u]];
		if (num >= k) return Query(lson[u], lson[v], l, m, k);
		return Query(rson[u], rson[v], m + 1, r, k - num);
	}
};

int n, m;
int a[maxn];
FuncSegTree T;

int sz;
int arr[maxn];
int map[maxn];
int revmap[maxn];

int Get(int x) {
	return std::lower_bound(arr + 1, arr + sz + 1, x) - arr;
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			arr[i] = a[i];
		}
		std::sort(arr + 1, arr + n + 1);
		sz = std::unique(arr + 1, arr + n + 1) - arr - 1;
		for (int i = 1, x; i <= n; ++i) {
			x = Get(a[i]);
			map[i] = x;
			revmap[x] = a[i];
		}
		T.Init(n);
		for (int i = 1; i <= n; ++i) T.rt[i] = T.Modify(T.rt[i - 1], 1, sz, map[i]);
		for (int i = 0, l, r; i < m; ++i) {
			scanf("%d%d", &l, &r);
			if (r - l + 1 < 3) {
				printf("-1\n");
				continue;
			}
			bool flag = false;
			for (int k = 1; k <= std::min(50, r - l - 1); ++k) {
				ll len[3];
				len[2] = revmap[T.Query(T.rt[l - 1], T.rt[r], 1, sz, r - l + 1 + 1 - k)];
				len[1] = revmap[T.Query(T.rt[l - 1], T.rt[r], 1, sz, r - l + 1 + 1 - k - 1)];
				len[0] = revmap[T.Query(T.rt[l - 1], T.rt[r], 1, sz, r - l + 1 + 1 - k - 2)];
				if (len[0] + len[1] > len[2]) {
					printf("%lld\n", len[0] + len[1] + len[2]);
					flag = true;
					break;
				}
			}
			if (!flag) printf("-1\n");
		}
	}
	return 0;
}
