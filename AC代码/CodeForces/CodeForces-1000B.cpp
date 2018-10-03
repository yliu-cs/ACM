#include <bits/stdc++.h>
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
const int maxn = 4e3 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x) {
	Finish_read = 0;
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

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	read(n); read(m);
	vector<int> a;
	a.pb(0);
	for (int i = 1, x; i <= n; ++i) {
		read(x);
		a.pb(x);
	}
	a.pb(m);
	vector<int> f[2];
	f[0].assign(a.size(), 0);
	f[1].assign(a.size(), 0);
	for (int i = int(a.size()) - 2; i >= 0; --i) {
		f[0][i] = f[1][i + 1];
		f[1][i] = (a[i + 1] - a[i]) + f[0][i + 1];
	}
	int ans = f[1][0];
	for (int i = 0; i + 1 < int(a.size()); ++i) {
		if (a[i + 1] - a[i] < 2) {
			continue;
		}
		int tp = (i & 1) ^ 1;
		int pSum = f[1][0] - f[tp][i];
		ans = max(ans, pSum + (a[i + 1] - a[i] - 1) + f[tp][i + 1]);
	}
	printf("%d\n", ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
