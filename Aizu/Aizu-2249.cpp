#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const int mod = 1e6;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

struct ac {
	int v;
	int dis;
	int cost;
};

int n, m;
int a, b, d, c;
int ans;
int dis[maxn];
int cost[maxn];
bool vis[maxn];
vector<ac> Adj[maxn];

void Dijkstra() {
	mem(dis, INF);
	mem(cost, INF);
	mem(vis, 0);
	dis[1] = 0;
	cost[1] = 0;
	for (int i = 1; i <= n; ++i) {
		int u = -1, dismin = INF, costmin = INF;
		for (int j = 1; j <= n; ++j) {
			if (!vis[j]) {
				if (dis[j] < dismin) {
					u = j;
					dismin = dis[j];
					costmin = cost[j];
				}
				else if (dis[j] == dismin) {
					if (cost[j] < costmin) {
						u = j;
						dismin = dis[j];
						costmin = cost[j];
					}
				}
			}
		}
		if (u == -1) {
			return;
		}
		vis[u] = 1;
		for (int j = 0; j < int(Adj[u].size()); ++j) {
			int v = Adj[u][j].v;
			if (!vis[v]) {
				if (dis[u] + Adj[u][j].dis < dis[v]) {
					dis[v] = dis[u] + Adj[u][j].dis;
					cost[v] = Adj[u][j].cost;
				}
				else if (dis[u] + Adj[u][j].dis == dis[v]) {
					if (Adj[u][j].cost < cost[v]) {
						cost[v] = Adj[u][j].cost;
					}
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
//#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//#endif
	while (~scanf("%d%d", &n, &m), n + m) {
		for (int i = 1; i <= m; ++i) {
			read(a); read(b); read(d); read(c);
			ac add;
			add.v = b;
			add.dis = d;
			add.cost = c;
			Adj[a].pb(add);
			add.v = a;
			Adj[b].pb(add);
		}
		Dijkstra();
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			Adj[i].clear();
			ans += cost[i];
		}
		printf("%d\n", ans);
	}
//#ifndef ONLINE_JUDGE
//	fclose(stdin);
//	fclose(stdout);
//	system("gedit out.txt");
//#endif
    return 0;
}
