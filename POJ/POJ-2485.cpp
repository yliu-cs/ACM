#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <set>
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 510;
const double eps = 1e-5;
const double e = 2.718281828459;

int t;
int n;
int dis[maxn];
int ans;
bool vis[maxn];
int dis_map[maxn][maxn];

void Prim() {
	mem(vis, 0);
	mem(dis, INF);
	dis[1] = 0;
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		int u = -1, min = INF;
		for (int j = 1; j <= n; ++j) {
			if (!vis[j] && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		vis[u] = 1;
		if (min > ans) {
			ans = min;
		}
		for (int j = 1; j <= n; ++j) {
			if (!vis[j] && dis_map[u][j] < dis[j]) {
				dis[j] = dis_map[u][j];
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
    	cin >> n;
    	for (int i = 1; i <= n; ++i) {
    		for (int j = 1; j <= n; ++j) {
    			cin >> dis_map[i][j];
			}
		}
		Prim();
		cout << ans << endl;
	}
    return 0;
}
