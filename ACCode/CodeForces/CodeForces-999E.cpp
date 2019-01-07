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

int n, m, s;
int input_u, input_v;
int cnt;
int ans;
vector<int> Adj[maxn];
bool vis[maxn];
bool used[maxn];

bool cmp(P a, P b) {
	return a.first > b.first;
}

void dfs(int v) {
	vis[v] = 1;
	for (auto it : Adj[v]) {
		if (!vis[it]) {
			dfs(it);
		}
	}
}

void find(int v) {
	used[v] = 1;
	++cnt;
	for (auto it : Adj[v]) {
		if (!used[it] && !vis[it]) {
			find(it);
		}
	}
}

int main() {
	//fre();
    cin >> n >> m >> s;
    --s;
    for (int i = 0; i < m; ++i) {
    	cin >> input_u >> input_v;
    	--input_u; --input_v;
    	Adj[input_u].pb(input_v);
    }
	// 找到未连接点
    dfs(s);
    vector<P> val;
    for (int i = 0; i < n; ++i) {
		// 未连接点出发寻找未连接点之间可连接的边
    	if (!vis[i]) {
			// 统计边数
    		cnt = 0;
    		mem(used, 0);
    		find(i);
			// 放入val数组(pair)
    		val.pb(mp(cnt, i));
		}
	}
	// 按照边数由大至小排序val数组
	sort(val.begin(), val.end(), cmp);
	ans = 0;
	// 遍历val数组
	for (auto it : val) {
		// 若此点未加入s点可达点的图中，则加入s点可达点的图中，并搜索此点可连接的边，加入s点可达点的图中
		if (!vis[it.second]) {
			++ans;
			dfs(it.second);
		}
	}
	cout << ans << endl;
    return 0;
}
