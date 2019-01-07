#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
#define XDebug(x) cout << #x << "=" << x << endl;
#define ArrayDebug(x,i) cout << #x << "[" << i << "]=" << x[i] << endl;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<ll,ll> PLL;
const int INF = 0x3f3f3f3f;
const int maxn = 1e7 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
template <class T>
inline bool read(T &ret) {
	char c;
	int sgn;
	if (c = getchar(), c == EOF) {
		return 0;
	}
	while (c != '-' && (c < '0' || c > '9')) {
		c = getchar();
	}
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while (c = getchar(), c >= '0' && c <= '9') {
		ret = ret * 10 + (c - '0');
	}
	ret *= sgn;
	return 1;
}
template <class T>
inline void out(T x) {
	if (x > 9) {
		out(x / 10);
	}
	putchar(x % 10 + '0');
}

int n, k;
vector<int> a, b;

bool check(double x) {
	vector<double> temp(n, 0.0);
	for (int i = 0; i < n; ++i) {
		temp[i] = a[i] - x * b[i];
	}
	sort(temp.begin(), temp.end());
	double ans = 0;
	for (int i = n - 1; i >= k; --i) {
		ans += temp[i];
	}
	return ans >= 0;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	while (read(n) && read(k) && n + k) {
		a.assign(n, 0);
		b.assign(n, 0);
		for (int i = 0; i < n; ++i) {
			read(a[i]);
		}
		for (int i = 0; i < n; ++i) {
			read(b[i]);
		}
		double left = 0, right = 1;
		while (right - left > eps) {
			double mid = (left + right) / 2;
			if (check(mid)) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		printf("%.0f\n", left * 100);	//G++
		// printf("%.0lf\n", left * 100);	C++
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
