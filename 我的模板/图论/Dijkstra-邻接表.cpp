#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

struct Link {
    // V:连接点，Dis:边权
    int V, Dis;
    Link(int _V = 0, int _Dis = 0): V(_V), Dis(_Dis) {}
};

// N:顶点数，E:边数
int N, E;
// 松弛更新数组
int Dis[maxn];
// 访问标记数组
bool Vis[maxn];
// 邻接表
std::vector<Link> Adj[maxn];

// 建图加边，U、V:顶点,Weight:权值
void AddEdge(int U, int V, int Weight) {
    Adj[U].push_back(Link (V, Weight));
    // 无向图反向建边
    Adj[V].push_back(Link (U, Weight));
}

// Dijkstra算法
int Dijkstra(int Start, int End) {
    memset(Dis, INF, sizeof(Dis));
    memset(Vis, 0, sizeof(Vis));
    Dis[Start] = 0;
    for (int i = 1; i <= N; ++i) {
        // 选择距起点权值和最小的顶点
        int U = -1, Min = INF;
        for (int j = 1; j <= N; ++j) {
            if (!Vis[j] && Dis[j] < Min) {
                U = j;
                Min = Dis[j];
            }
        }
        // 查询失败，两点不相连 
        if (U == -1) {
            return -1;
        }
        // 寻找到最短路
        else if (U == End) {
            return Dis[End];
        }
        // 标记
        Vis[U] = 1;
        // 松弛
        for (int j = 0; j < int(Adj[U].size()); ++j) {
            int V = Adj[U][j].V;
            if (!Vis[V] && Dis[U] + Adj[U][j].Dis < Dis[V]) {
                Dis[V] = Dis[U] + Adj[U][j].Dis;
            }
        }
    }
}
