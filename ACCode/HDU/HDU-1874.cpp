#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
// 正无穷(可以用memset)
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

struct connect {
    int v;
    int time;
};

int dis[maxn],N,M;
bool vis[maxn];
vector<connect> Adj[maxn];

// 迪杰斯特拉求最短路
void Dijkstra(int s) {
    mem(dis, INF);
    mem(vis, 0);
    dis[s] = 0;
    for (int i = 0;i < N;++i) {
        int u = -1,min = INF;
        for (int j = 0;j < N;++j) {
            if (vis[j] == 0 && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = 1;
        for (int j = 0;j < Adj[u].size();++j) {
            int v = Adj[u][j].v;
            if (vis[v] == 0 && dis[u] + Adj[u][j].time < dis[v]) {
                dis[v] = dis[u] + Adj[u][j].time;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> N >> M) {
        while (M--) {
            int A,B,C;
            cin >> A >> B >> C;
            connect add;
            add.v = B;
            add.time = C;
            Adj[A].push_back(add);
            add.v = A;
            add.time = C;
            Adj[B].push_back(add);
        }
        int st,en;
        cin >> st >> en;
        Dijkstra(st);
        if (dis[en] == INF) {
            cout << -1 << endl;
        }
        else {
            cout << dis[en] << endl;
        }
		// 清空邻接表
        for (int i = 0;i < N;++i) {
            Adj[i].clear();
        }
    }
    return 0;
}
