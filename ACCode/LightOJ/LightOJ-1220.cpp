#include <bits/stdc++.h>
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
const double eps = 1e-8;
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

bool IsPrime[maxn];
ll Prime[maxn / 10];
int tot;
vector<ll> ResolveAns;

inline ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

void PrimeInit() {
	mem(IsPrime, 1);
	IsPrime[1] = 0;
	tot = 0;
	for (ll i = 2; i < maxn; ++i) {
		if (IsPrime[i]) {
			Prime[tot++] = i;
			for (ll j = i * i; j < maxn; j += i) {
				IsPrime[j] = 0;
			}
		}
	}
}

void Resolve(ll x) {
	ResolveAns.clear();
	int num = 0;
	while (x > 1 && Prime[num] * Prime[num] <= x && num < tot) {
		if (!(x % Prime[num])) {
			int cnt = 0;
			while (!(x % Prime[num])) {
				x /= Prime[num];
				cnt++;
			}
			ResolveAns.pb(cnt);
		}
		num++;
	}
	if (x > 1) {
		ResolveAns.pb(1);
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	PrimeInit();
	ll T;
	read(T);
	for (ll Case = 1, N; Case <= T; ++Case) {
		bool symbol = 0;
		read(N);
		if (N < 0) {
			N = -N;
			symbol = 1;
		}
		Resolve(N);
		ll ans = ResolveAns[0];
		for (int i = 1; i < int(ResolveAns.size()); ++i) {
			ans = gcd(ans, ResolveAns[i]);
		}
		if (symbol) {
			while (!(ans % 2)) {
				ans >>= 1;
			}
		}
		printf("Case %lld: %lld\n", Case, ans);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
