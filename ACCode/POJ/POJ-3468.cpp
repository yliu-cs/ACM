//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x) {
	Finish_read = 1;
	x = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -1;
		}
		if (ch == EOF) {
			return;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	x *= f;
	Finish_read = 1;
};

ll sum[maxn << 2], lazy[maxn << 2];

void PushUp(int root) {
	sum[root] = sum[root << 1] + sum[root << 1 | 1];
}

void PushDown(int root, int leftnum, int rightnum) {
	if (lazy[root]) {
		lazy[root << 1] += lazy[root];
		lazy[root << 1 | 1] += lazy[root];
		sum[root << 1] += lazy[root] * leftnum;
		sum[root << 1 | 1] += lazy[root ] * rightnum;
		lazy[root] = 0;
	}
}

void Build(int left, int right, int root) {
	lazy[root] = 0;
	if (left == right) {
		read(sum[root]);
		return;
	}
	int mid = (left + right) >> 1;
	Build(left, mid, root << 1);
	Build(mid + 1, right, root << 1 | 1);
	PushUp(root);
}

void IntervalUpdate(int operateleft, int operateright, int value, int left, int right, int root) {
	if (operateleft <= left && operateright >= right) {
		sum[root] += value * (right - left + 1);
		lazy[root] += value;
		return;
	}
	int mid = (left + right) >> 1;
	PushDown(root, mid - left + 1, right - mid);
	if (operateleft <= mid) {
		IntervalUpdate(operateleft, operateright, value, left, mid, root << 1);
	}
	if (operateright > mid) {
		IntervalUpdate(operateleft, operateright, value, mid + 1, right, root << 1 | 1);
	}
	PushUp(root);
}

ll Query(int operateleft, int operateright, int left, int right, int root) {
	if (operateleft <= left && operateright >= right) {
		return sum[root];
	}
	int mid = (left + right) >> 1;
	PushDown(root, mid - left + 1, right - mid);
	ll ans = 0;
	if (operateleft <= mid) {
		ans += Query(operateleft, operateright, left, mid, root << 1);
	}
	if (operateright > mid) {
		ans += Query(operateleft, operateright, mid + 1, right, root << 1 | 1);
	}
	return ans;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, q;
	read(n); read(q);
	Build(1, n, 1);
	while (q--) {
		char op;
		cin >> op;
		if (op == 'C') {
			int a, b, c;
			read(a); read(b); read(c);
			IntervalUpdate(a, b, c, 1, n, 1);
		}
		else {
			int a, b;
			read(a); read(b);
			printf("%lld\n", Query(a, b, 1, n, 1));
		}
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
