#include <bits/stdc++.h>

const int maxn = "Edit";

// 链式前向星存图
struct Edge {
    int V, Weight, Next;
};

Edge edges[maxn << 1];
int Head[maxn];
int Tot;

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V, int Weight) {
    edges[Tot] = Edge {V, Weight, Head[U]};
    Head[U] = Tot++;
}

struct LCAOnline {
    // 节点深度
    int Rmq[maxn << 1];
    // 深搜遍历顺序
    int Vertex[maxn << 1];
    // 节点在深搜中第一次出现的位置
    int First[maxn];
    // 记录父节点
    int Parent[maxn];
    // 记录与根节点距离
    int Dis[maxn];
    // 遍历节点数量
    int LCATot;
    
    // 最小值对应下标
    int Dp[maxn << 1][20];
    
    // RMQ初始化
    void Work(int N) {
        for (int i = 1; i <= N; ++i) {
            Dp[i][0] = i;
        }
        for (int j = 1; (1 << j) <= N; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= N; ++i) {
                Dp[i][j] = Rmq[Dp[i][j - 1]] < Rmq[Dp[i + (1 << (j - 1))][j - 1]] ? Dp[i][j - 1] : Dp[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    // 深搜
    void Dfs(int Cur, int Pre, int Depth) {
        Vertex[++LCATot] = Cur;
        First[Cur] = LCATot;
        Rmq[LCATot] = Depth;
        Parent[Cur] = Pre;
        for (int i = Head[Cur]; ~i; i = edges[i].Next) {
            if (edges[i].V == Pre) {
                continue;
            }
            Dis[edges[i].V] = Dis[Cur] + edges[i].Weight;
            Dfs(edges[i].V, Cur, Depth + 1);
            Vertex[++LCATot] = Cur;
            Rmq[LCATot] = Depth;
        }
    }
    
    // RMQ查询
    int Query(int Left, int Right) {
        if (Left > Right) {
            swap(Left, Right);
        }
        int Len = int(log2(Right - Left + 1));
        return Rmq[Dp[Left][Len]] <= Rmq[Dp[Right - (1 << Len) + 1][Len]] ? Dp[Left][Len] : Dp[Right - (1 << Len) + 1][Len];
    }
    
    // LCA初始化
    void Init(int Root, int NodeNum) {
        memset(Dis, 0, sizeof(Dis));
        LCATot = 0;
        Dfs(Root, 0, 0);
        Parent[1] = 0;
        Work(2 * NodeNum - 1);
    }

    // 查询节点U、V的距离
    int GetDis(int U, int V) {
        return Dis[U] + Dis[V] - 2 * Dis[LCA(U, V)];
    }

    // 查询节点U、V的最近公共祖先(LCA)
    int LCA(int U, int V) {
        return Vertex[Query(First[U], First[V])];
    }
}LCA;

