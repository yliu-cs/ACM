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
typedef pair<ll,ll> PLL;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
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

struct Star {
	int i, j, l;
	Star(int _i = 0, int _j = 0, int _l = 0): i(_i), j(_j), l(_l) {}
};

int n, m;
char plat[maxn][maxn];
bool flag[maxn][maxn];
bool ok;
vector<PII> bit;
vector<Star> ans;

void judge(PII x) {
	int res = 0;
	while (x.first - res - 1 >= 1 &&
			x.first + res + 1 <= n &&
			x.second - res - 1 >= 1 &&
			x.second + res + 1 <= m &&
			plat[x.first - res - 1][x.second] == '*' &&
			plat[x.first + res + 1][x.second] == '*' &&
			plat[x.first][x.second - res - 1] == '*' &&
			plat[x.first][x.second + res + 1] == '*') {
		flag[x.first - res - 1][x.second] = 1;
		flag[x.first + res + 1][x.second] = 1;
		flag[x.first][x.second - res - 1] = 1;
		flag[x.first][x.second + res + 1] = 1;
		res++;
	}
	if (res > 0) {
		flag[x.first][x.second] = 1;
		ans.pb(Star {x.first, x.second, res});
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> plat[i][j];
			if (plat[i][j] == '*') {
				bit.pb(mp(i, j));
			}
		}
	}
	mem(flag, 0);
	for (auto it : bit) {
		judge(it);
	}
	ok = 1;
	for (auto it : bit) {
		if (!flag[it.first][it.second]) {
			ok = 0;
			break;
		}
	}
	if (ok) {
		printf("%d\n", int(ans.size()));
		for (auto it : ans) {
			printf("%d %d %d\n", it.i, it.j, it.l);
		}
	}
	else {
		printf("-1\n");
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
