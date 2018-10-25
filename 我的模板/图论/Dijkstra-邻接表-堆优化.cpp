#include <bits/stdc++.h>

const int INF = "Edit";
const int maxn = "Edit";

struct Link {
    // V:连接点，Dis:边权
    int V, Dis;
    Link(int _V = 0, int _Dis = 0): V(_V), Dis(_Dis) {}
};

// N:顶点数，E:边数
int N, E;
// 松弛更新数组
int Dis[maxn];
// 邻接表
std::vector<Link> Adj[maxn];

// 建图加边，U、V:顶点,Weight:权值
void AddEdge(int U, int V, int Weight) {
    Adj[U].push_back(Link (V, Weight));
    // 无向图反向建边
    Adj[V].push_back(Link (U, Weight));
}

// Dijkstra堆优化算法
void Dijkstra(int Start) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > Que;
    memset(Dis, INF, sizeof(Dis));
    Dis[Start] = 0;
    Que.push(std::make_pair(0, Start));
    while (!Que.empty()) {
        std::pair<int, int> Keep = Que.top();
        Que.pop();
        int V = Keep.second;
        if (Dis[V] < Keep.first) {
            continue;
        }
        for (int i = 0; i < int(Adj[V].size()); ++i) {
            Link Temp = Adj[V][i];
            if (Dis[Temp.V] > Dis[V] + Temp.Dis) {
                Dis[Temp.V] = Dis[V] + Temp.Dis;
                Que.push(std::make_pair(Dis[Temp.V], Temp.V));
            }
        }
    }
}

