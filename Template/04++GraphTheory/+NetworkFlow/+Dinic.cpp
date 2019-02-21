#include <bits/stdc++.h>

const int INF = "Edit";
const int maxn = "Edit";

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
// N:顶点数，E:边数
int N, E;
// Bfs分层深度
int Depth[maxn];
// 当前弧优化
int Current[maxn];

// 链式向前星初始化
void GraphInit() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

// 添加一条由U至V权值为Weight的边
void AddEdge(int U, int V, int Weight, int ReverseWeight = 0) {
    edges[Tot] = Edge (V, Weight, Head[U]);
    Head[U] = Tot++;
    // 反向建边
    edges[Tot] = Edge (U, ReverseWeight, Head[V]);
    Head[V] = Tot++;
}

// Bfs搜索分层图，Start:起点，End:终点
bool Bfs(int Start, int End) {
    memset(Depth, -1, sizeof(Depth));
    std::queue<int> Que;
    Depth[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int Cur = Que.front();
        Que.pop();
        for (int i = Head[Cur]; ~i; i = edges[i].Next) {
            if (Depth[edges[i].V] == -1 && edges[i].Weight > 0) {
                Depth[edges[i].V] = Depth[Cur] + 1;
                Que.push(edges[i].V);
            }
        }
    }
    return Depth[End] != -1;
}

// Dfs搜索增广路径，Cur:当前搜索顶点，End:终点，NowFlow:当前最大流
int Dfs(int Cur, int End, int NowFlow) {
    // 搜索到终点或者可用当前最大流为0返回
    if (Cur == End || NowFlow == 0) return NowFlow;
    // UsableFlow:可用流量，当达到NowFlow时不可再增加，FindFlow:递归深搜到的最大流
    int UsableFlow = 0, FindFlow;
    // &i=Current[Cur]为当前弧优化，每次更新Current[Cur]
    for (int &i = Current[Cur]; ~i; i = edges[i].Next) {
        if (edges[i].Weight > 0 && Depth[edges[i].V] == Depth[Cur] + 1) {
            FindFlow = Dfs(edges[i].V, End, std::min(NowFlow - UsableFlow, edges[i].Weight));
            if (FindFlow > 0) {
                edges[i].Weight -= FindFlow;
                // 反边
                edges[i ^ 1].Weight += FindFlow;
                UsableFlow += FindFlow;
                if (UsableFlow == NowFlow) return NowFlow;
            }
        }
    }
    // 炸点优化
    if (!UsableFlow) Depth[Cur] = -2;
    return UsableFlow;
}

// Dinic算法，Start:起点，End:终点（图中所有顶点均在[Start,End]范围内）
int Dinic(int Start, int End) {
    int MaxFlow = 0;
    while (Bfs(Start, End)) {
        // 当前弧优化
        for (int i = Start; i <= End; ++i) Current[i] = Head[i];
        MaxFlow += Dfs(Start, End, INF);
    }
    // 返回结果
    return MaxFlow;
}

