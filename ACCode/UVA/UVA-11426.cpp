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
const int maxn = 4e6 + 5;
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

bool IsPrime[maxn];
int phi[maxn];
int prime[maxn];
ll f[maxn];
int tot;

void PhiPrime() {
	mem(IsPrime, 0);
	mem(f, 0);
	phi[1] = 1;
	tot = 0;
	for (int i = 2; i < maxn; ++i) {
		if (!IsPrime[i]) {
			prime[tot++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < tot && i * prime[j] < maxn; ++j) {
			IsPrime[i * prime[j]] = 1;
			if (!(i % prime[j])) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else {
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			}
		}
		for (int j = 1; i * j < maxn; ++j) {
			f[i * j] += j * phi[i];
		}
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	PhiPrime();
	int n;
	while (~scanf("%d", &n) && n) {
		ll ans = 0;
		for (int i = n; i > 1; --i) {
			ans += f[i];
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