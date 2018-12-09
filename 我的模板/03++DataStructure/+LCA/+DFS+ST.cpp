#include <bits/stdc++.h>

const int maxn = "Edit";

// 节点深度
int Rmq[maxn << 1];

struct ST {
    // 最小值对应下标
    int Dp[maxn << 1][20];
    // RMQ初始化
    void init(int N) {
        for (int i = 1; i <= N; ++i) {
            Dp[i][0] = i;
        }
        for (int j = 1; (1 << j) <= N; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= N; ++i) {
                Dp[i][j] = Rmq[Dp[i][j - 1]] < Rmq[Dp[i + (1 << (j - 1))][j - 1]] ? Dp[i][j - 1] : Dp[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    // RMQ查询
    int Query(int A, int B) {
        if (A > B) {
            std::swap(A, B);
        }
        int K = int(log2(B - A + 1));
        return Rmq[Dp[A][K]] <= Rmq[Dp[B - (1 << K) + 1][K]] ? Dp[A][K] : Dp[B - (1 << K) + 1][K];
    }
};

// 边
struct Edge {
    int V, Next;
};

// 链式前向星存树边图
Edge edges[maxn << 1];
int Head[maxn];
int Tot;

// 深搜遍历顺序
int Vertex[maxn << 1];
// 节点在深搜中第一次出现的位置
int First[maxn];
// 记录父节点
int Parent[maxn];
// 遍历节点数量
int LCATot;
ST St;

// 链式前向星存图初始化
void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

// 链式前向星存图添加一条由U至V的边
void AddEdge(int U, int V) {
    edges[Tot] = Edge {V, Head[U]};
    Head[U] = Tot++;
}

// 深搜，U:当前搜索节点，Pre:U的前驱节点，Depth:树上深度
void LCADfs(int Cur, int Pre, int Depth) {
    Vertex[++LCATot] = Cur;
    First[Cur] = LCATot;
    Rmq[LCATot] = Depth;
    Parent[Cur] = Pre;
    for (int i = Head[Cur]; ~i; i = edges[i].Next) {
        if (edges[i].V == Pre) {
            continue;
        }
        LCADfs(edges[i].V, Cur, Depth + 1);
        Vertex[++LCATot] = Cur;
        Rmq[LCATot] = Depth;
    }
}

// LCA查询前的初始化，Root:根节点，NodeNum:节点数量
void LCA_Init(int Root, int NodeNum) {
    LCATot = 0;
    LCADfs(Root, 0, 0);
    St.init(2 * NodeNum - 1);
}

// 查询节点U和节点V的LCA
int Query_LCA(int U, int V) {
    return Vertex[St.Query(First[U], First[V])];
}

