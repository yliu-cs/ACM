#include <bits/stdc++.h>

const int maxn = "Edit";
const int INF = "Edit";

// 边
struct Edge {
    // V:连接点，Weight:权值，Next:上一条边的编号
    int V, Weight, Next;
};

// 边，一定要开到足够大
Edge edges[maxn << 1];
// Head[i]为点i上最后一条边的编号
int Head[maxn];
// 增加边时更新编号
int Tot;
// 松弛更新数组，最短路
int Dis[maxn];

// 链式前向星初始化
void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

// 添加一条U至V权值为Weight的边
void AddEdge(int U, int V, int Weight) {
    edges[Tot] = Edge (V, Weight, Head[U]);
    Head[U] = Tot++;
}

// 最短路优化堆排序规则
struct Cmp {
    bool operator() (const int &A, const int &B) {
        return Dis[A] > Dis[B];
    }
};

// N:顶点数，E:边数
int N, E;

// Dijkstra算法，Start:起点
void Dijkstra(int Start) {
    std::priority_queue<int, std::vector<int>, Cmp> Que;
    memset(Dis, INF, sizeof(Dis));
    Dis[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int U = Que.top(); Que.pop();
        for (int i = Head[U]; ~i; i = edges[i].Next) {
            if (Dis[edges[i].V] > Dis[U] + edges[i].Weight) {
                Dis[edges[i].V] = Dis[U] + edges[i].Weight;
                Que.push(edges[i].V);
            }
        }
    }
}

