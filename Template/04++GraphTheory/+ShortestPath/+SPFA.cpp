#include <bits/stdc++.h>

const int INF = "Edit";
const int maxn = "Edit";

// 边
struct Edge {
    // V:连接点，Dis:边权
    int V, Dis;
};

// N:顶点数，E:边数
int N, E;
// 访问标记数组
bool Vis[maxn];
// 每个点的入队列次数
int Cnt[maxn];
// 最短路数组
int Dis[maxn];
// 邻接表
std::vector<Edge> Adj[maxn];

// 建图加边，U、V之间权值为Weight的边
void AddEdge (int U, int V, int Weight) {
    Adj[U].push_back(Edge (V, Weight));
    // 无向图建立反向边
    Adj[V].push_back(Edge (U, Weight));
}

// SPFA算法，Start:起点
bool SPFA(int Start) {
    memset(Vis, false, sizeof(Vis));
    memset(Dis, INF, sizeof(Dis));
    memset(Cnt, 0, sizeof(Cnt));
    Vis[Start] = true;
    Dis[Start] = 0;
    Cnt[Start] = 1;
    std::queue<int> Que;
    while (!Que.empty()) {
        Que.pop();
    }
    Que.push(Start);
    while (!Que.empty()) {
        int U = Que.front();
        Que.pop();
        Vis[U] = false;
        for (int i = 0; i < int(Adj[U].size()); ++i) {
            int V = Adj[U][i].V;
            if (Dis[V] > Dis[U] + Adj[U][i].Dis) {
                Dis[V] = Dis[U] + Adj[U][i].Dis;
                if (!Vis[V]) {
                    Vis[V] = true;
                    Que.push(V);
                    // Cnt[i]为i顶点入队列次数，用来判定是否存在负环回路
                    if (++Cnt[V] > N) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

