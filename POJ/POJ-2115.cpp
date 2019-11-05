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

ll extendgcd(ll a, ll b, ll &x, ll &y) {
	if (a == 0 && b == 0) {
		return -1;
	}
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll d = extendgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll A, B, C, k;
	while (~scanf("%lld%lld%lld%lld", &A, &B, &C, &k) && A + B + C + k) {
		ll c = B - A;
		ll a = C;
		ll b = ll(1) << k;
		ll x, y;
		ll d = extendgcd(a, b, x, y);
		if (c % d) {
			printf("FOREVER\n");
			continue;
		}
		ll s = b / d;
		ll _min = (x * c / d % s + s) % s;
		printf("%lld\n", _min);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
