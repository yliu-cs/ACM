#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
const int maxn = 20;

// N:顶点数，E:边数
int N, E;
// 分层数组
int Depth[maxn];
// 邻接矩阵
int Adj[maxn][maxn];

// Bfs搜索分层图，Start:起点，End:终点
bool Bfs(int Start, int End) {
    std::queue<int> Que;
    memset(Depth, -1, sizeof(Depth));
    Depth[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int Vertex = Que.front();
        Que.pop();
        for (int i = 1; i <= N; ++i) {
            if (Depth[i] == -1 && Adj[Vertex][i]) {
                // 分层编号
                Depth[i] = Depth[Vertex] + 1;
                Que.push(i);
            }
        }
    }
    return Depth[End] > 0;
}

// Dfs搜索增广路径，Vertex:当前搜索顶点，End:终点，NowFlow:当前最大流量
int Dfs(int Vertex, int End, int NowFlow) {
    // 搜索到终点结束
    if (Vertex == End) {
        return NowFlow;
    }
    int FindFlow = 0;
    // 枚举顶点
    for (int i = 1; i <= N; ++i) {
        if (Adj[Vertex][i] && Depth[i] == Depth[Vertex] + 1) {
            FindFlow = Dfs(i, End, std::min(NowFlow, Adj[Vertex][i]));
            if (FindFlow) {
                // 找到增广路径后更新邻接矩阵残留网
                Adj[Vertex][i] -= FindFlow;
                Adj[i][Vertex] += FindFlow;
                // 返回搜索结果
                return FindFlow;
            }
        }
    }
    // 炸点优化
    if (!FindFlow) {
        Depth[Vertex] = -2;
    }
    // 未找到增广路径
    return false;
}

// Dinic算法，Start:起点，End:终点
int Dinic(int Start, int End) {
    // MaxFlow:最大流
    int MaxFlow = 0;
    // 分层搜索增广路径直至终点无法分层
    while (Bfs(Start, End)) {
        MaxFlow += Dfs(Start, End, INF);
    }
    // 返回结果
    return MaxFlow;
}

