#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
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

int t;
int r, c;
int ans;
int maze[maxn][maxn];
int dp[maxn][maxn];

int _abs(int a) {
	return a >= 0 ? a : -a;
}

int dfs(int x, int y, int h) {
	if (x < 0 || y < 0 || x >= r || y >= c || h <= maze[x][y]) {
		return 0;
	}
	if (dp[x][y] >= 0) {
		return dp[x][y];
	}
	for (int i = -1; i < 2; ++i) {
		for (int j = -1; j < 2; ++j) {
			if (_abs(i) != _abs(j)) {
				int nx = x + i, ny = y + j;
				int temp = dfs(nx, ny, maze[x][y]) + 1;
				dp[x][y] = temp > dp[x][y] ? temp : dp[x][y];
			}
		}
	}
	return dp[x][y];
}

int main() {
	//fre();
	while (~scanf("%d%d", &r, &c)) {
		ans = 0;
		mem(dp, -1);
		mem(maze, 0);
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				scanf("%d", &maze[i][j]);
			}
		}
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				int temp = dfs(i, j, INF);
				if (temp > ans) {
					ans = temp;
				}
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
