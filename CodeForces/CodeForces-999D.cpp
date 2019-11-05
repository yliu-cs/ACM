#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 20;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int main(){
    //fre();
	int n, m;
	scanf("%d%d", &n, &m);
	int k = n / m;
	vector<int> a(n);
	vector<vector<int>> val(m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		val[a[i] % m].pb(i);
	}
	ll ans = 0;
	vector<P> fre;
	for (int i = 0; i < (m << 1); ++i) {
		int cur = i % m;
		while (val[cur].size() > k) {
			int elem = val[cur].back();
			val[cur].pop_back();
			fre.pb(mp(elem, i));
		}
		while (val[cur].size() < k && !fre.empty()) {
			int elem = fre.back().first;
			int mmod = fre.back().second;
			fre.pop_back();
			val[cur].pb(elem);
			a[elem] += i - mmod;
			ans += i - mmod;
		}
	}
	printf("%lld\n", ans);
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
    return 0;
}
