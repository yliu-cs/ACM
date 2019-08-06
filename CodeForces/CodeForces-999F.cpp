#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 5e3+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

// 状态转移方程：dp[x][y]表示有x个喜欢数字相同的人，分配共y张此数字的卡片的最大值
/*
	for (int i = 0; i <= k; ++i) {
		dp[x + 1][y + i] = max(dp[x + 1][y + i], dp[x][y] + h[i]);
	}
*/

int dp[520][520 * 12];

int main() {
	//fre();
	int n, k;
	scanf("%d%d", &n, &k);
	map<int, int> c;
	for (int i = 0; i < k * n; ++i) {
		int x;
		scanf("%d", &x);
		c[x]++;
	}
	map<int, int> f;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		f[x]++;
	}
	vector<int> h(k + 1);
	for (int i = 1; i <= k; ++i) {
		scanf("%d", &h[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n * k; ++j) {
			for (int cur = 0; cur <= k; ++cur) {
				dp[i + 1][j + cur] = max(dp[i + 1][j + cur], dp[i][j] + h[cur]);
			}
		}
	}
	int ans = 0;
	for (auto it : f) {
		if (it.second) {
			ans += dp[it.second][c[it.first]];
		}
	}
	printf("%d\n", ans);
    return 0;
}
