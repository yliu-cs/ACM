
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
const int maxn = 3e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;

/*
 * 一张图中n个点被分割为若干层
 * 每一层之内的点不相连
 * x层内的所有点和x+1层内所有点的距离全部以长度c无向连接
 * 随后有m条额外的边，依次输入两点以及权值，最后求1~n的最短路。
 *
 * 建图时用n + 1~2 * n和2 * n + 1 ~ 3 * n分别表示层级关系有向入边和有向出边
 * 将权值设置为相应的c或0。
 */

struct connect {
    int v;
    int dis;
    bool operator < (const connect &a)const {
        return dis > a.dis;
    }
};

int t;
int n, m, c;
int dis[maxn];
bool vis[maxn];
vector<connect> Adj[maxn];

// 建边
void build_edge(int u, int v, int dis) {
    connect add;
    add.v = v;
    add.dis = dis;
    Adj[u].push_back(add);
}

// 堆优化迪杰斯特拉跑最短路
void Dijkstra() {
    mem(dis, INF);
    mem(vis, 0);
    dis[1] = 0;
    priority_queue<connect> que;
    connect temp_push;
    temp_push.v = 1;
    temp_push.dis = 0;
    que.push(temp_push);
    while (!que.empty()) {
        connect keep = que.top();
        que.pop();
        int v = keep.v;
        if (dis[v] < keep.dis || vis[v]) {
            continue;
        }
        if (v == n) {
            return;
        }
        vis[v] = 1;
        for (int i = 0; i < Adj[v].size(); ++i) {
            connect e = Adj[v][i];
            if (!vis[e.v] && dis[e.v] > dis[v] + e.dis) {
                dis[e.v] = dis[v] + e.dis;
                connect keep_add;
                keep_add.v = e.v;
                keep_add.dis = dis[e.v];
                que.push(keep_add);
            }
        }
    }
}

int main() {
	// "cin"&"cout"会TLE
    scanf("%d",&t);
    for (int u = 1; u <= t; ++u) {
        scanf("%d%d%d",&n,&m,&c);
        for (int i = 1; i <= n; ++i) {
            int temp;
            scanf("%d",&temp);
            build_edge(i, n + temp, c);
            build_edge(2 * n + temp, i, 0);
            if (--temp) {
                build_edge(n + temp, i, 0);
                build_edge(i, 2 * n + temp, c);
            }
        }
        for (int i = 1; i <= m; ++i) {
            int extra_u, extra_v, extra_dis;
            scanf("%d%d%d",&extra_u,&extra_v,&extra_dis);
            build_edge(extra_u, extra_v, extra_dis);
            build_edge(extra_v, extra_u, extra_dis);
        }
        Dijkstra();
        if (dis[n] == INF) {
            dis[n] = -1;
        }
        printf("Case #%d: %d\n",u,dis[n]);
        for (int i = 1; i <= 3 * n; ++i) {
            Adj[i].clear();
        }
    }
    return 0;
}
