#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
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

int a[maxn], b[maxn], c[maxn], d[maxn];
int ab[maxn * maxn], cd[maxn * maxn];

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n;
	read(n);
	vector<int> a, b, c, d;
	for (int i = 0, x; i < n; ++i) {
		read(x); a.pb(x);
		read(x); b.pb(x);
		read(x); c.pb(x);
		read(x); d.pb(x);
	}
	vector<int> ab, cd;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ab.pb(a[i] + b[j]);
			cd.pb(-(c[i] + d[j]));
		}
	}
	int ans = 0;
	sort(cd.begin(), cd.end());
	for (int i = 0; i < int(ab.size()); ++i) {
		int index = lower_bound(cd.begin(), cd.end(), ab[i]) - cd.begin();
		if (cd[index] == ab[i]) {
			int cnt = 0;
			for (int j = index; j < int(cd.size()); ++j) {
				if (cd[j] == ab[i]) {
					cnt++;
				}
				else {
					break;
				}
			}
			ans += cnt;
		}
	}
	printf("%d\n", ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
