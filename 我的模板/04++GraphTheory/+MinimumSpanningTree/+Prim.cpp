#include <bits/stdc++.h>

const int INF = "Edit";
const int maxn = "Edit";

struct Edge {
    // V:连接点，Dis:边权
    int V, Dis;
    Edge(int _V = 0, int _Dis = 0): V(_V), Dis(_Dis) {}
};

// N:顶点数，E:边数
int N, E;
// 松弛更新权值数组
int Dis[maxn];
// 访问标记数组
int Vis[maxn];
// 邻接表
std::vector<Edge> Adj[maxn];

// 建图加边，U、V:顶点,Weight:权值
void AddEdge(int U, int V, int Weight) {
    Adj[U].push_back(Edge (V, Weight));
    // 无向图反向建边
    Adj[V].push_back(Edge (U, Weight));
}

// Prim算法
int Prim(int Start) {
    memset(Dis, INF, sizeof(Dis));
    memset(Vis, 0, sizeof(Vis));
    Dis[Start] = 0;
    int Res = 0;
    for (int i = 1; i <= N; ++i) {
        // 选择距已生成树权值最小的顶点
        int U = -1, Min = INF;
        for (int j = 1; j <= N; ++j) {
            if (!Vis[j] && Dis[j] < Min) {
                U = j;
                Min = Dis[j];
            }
        }
        // 更新、标记
        Vis[U] = 1;
        Res += Min;
        // 松弛
        for (int j = 0; j < int(Adj[U].size()); ++j) {
            int V = Adj[U][j].V;
            if (!Vis[V] && Adj[U][j].Dis < Dis[V]) {
                Dis[V] = Adj[U][j].Dis;
            }
        }
    }
    // 返回结果
    return Res;
}
