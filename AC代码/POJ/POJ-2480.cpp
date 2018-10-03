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
typedef pair<ll,ll> PLL;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
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

ll Phi(ll x) {
	ll res = x;
	for (ll i = 2; i < int(sqrt(x * 1.0)) + 1; ++i) {
		if (!(x % i)) {
			res = res / i * (i - 1);
			while (!(x % i)) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		res = res / x * (x - 1);
	}
	return res;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll n;
	while (~scanf("%lld", &n)) {
		ll ans = 0;
		for (ll i = 1; i <= int(sqrt(n)); ++i) {
			if (i * i == n) {
				ans += i * Phi(i);
				continue;
			}
			if (!(n % i)) {
				ans += i * Phi(n / i) + n / i * Phi(i);
			}
		}
		printf("%lld\n", ans);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
