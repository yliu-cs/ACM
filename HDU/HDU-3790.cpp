#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

struct node {
    int v;
    int dis;
    int cost;
    node(): v(0), dis(0), cost(0) {}
};

int n, m;
int a, b, d, p;
int s, t;
int dis[maxn];
int cost[maxn];
bool vis[maxn];
vector<node> Adj[maxn];

// 迪杰斯特拉求单源最短路
void Dijkstra() {
    mem(dis, INF);
    mem(vis, 0);
    dis[s] = 0;
    cost[s] = 0;
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
                    u = j;
                    costmin = cost[j];
                }
            }
        }
        if (u == t) {
            return;
        }
        vis[u] = 1;
		// 多权值松弛
        for (int j = 0; j < int(Adj[u].size()); ++j) {
            int v = Adj[u][j].v;
            if (!vis[v]) {
                if (dis[v] > dis[u] + Adj[u][j].dis) {
                    dis[v] = dis[u] + Adj[u][j].dis;
                    cost[v] = cost[u] + Adj[u][j].cost;
                }
                else if (dis[v] == dis[u] + Adj[u][j].dis) {
                    cost[v] = cost[u] + Adj[u][j].cost;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &m), n + m) {
        while (m--) {
            read(a); read(b); read(d); read(p);
            node add;
            add.v = b;
            add.dis = d;
            add.cost = p;
            Adj[a].pb(add);
            add.v = a;
            Adj[b].pb(add);
        }
        read(s); read(t);
        Dijkstra();
        printf("%d %d\n", dis[t], cost[t]);
        for (int i = 1; i <= n; ++i) {
            Adj[i].clear();
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
