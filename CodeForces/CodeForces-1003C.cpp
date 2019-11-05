#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 102;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int main() {
	//fre();
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> sum(n + 1);
	sum[0] = 0;
	int x;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		sum[i] = sum[i - 1] + x;
	}
	double ans = -INF;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + k - 1; j <= n; ++j) {
			double temp = (double)(sum[j] - sum[i -1]) / (double)(j - i + 1);
			ans = temp > ans ? temp : ans;
		}
	}
	printf("%.15lf\n", ans);
    return 0;
}
