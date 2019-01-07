#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 1e4 + 5;

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
            swap(A, B);
        }
        int K = int(log2(B - A + 1));
        return Rmq[Dp[A][K]] <= Rmq[Dp[B - (1 << K) + 1][K]] ? Dp[A][K] : Dp[B - (1 << K) + 1][K];
    }
};

// 边
struct Link {
    int V, Next;
};

// 链式前向星存树边图
Link edges[maxn << 1];
int Head[maxn];
int Tot;

// 深搜遍历顺序
int Vertex[maxn << 1];
// 节点在深搜中第一次出现的位置
int First[maxn];
// 遍历节点数量
int Cnt;
ST St;

// 链式前向星存图初始化
void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

// 链式前向星存图添加一条由U至V的边
void AddEdge(int U, int V) {
    edges[Tot] = Link {V, Head[U]};
    Head[U] = Tot++;
}

// 深搜，U:当前搜索节点，Pre:U的前驱节点，Depth:树上深度
void Dfs(int U, int Pre, int Depth) {
    Vertex[++Cnt] = U;
    Rmq[Cnt] = Depth;
    First[U] = Cnt;
    for (int i = Head[U]; i != -1; i = edges[i].Next) {
        int V = edges[i].V;
        if (V == Pre) {
            continue;
        }
        Dfs(V, U, Depth + 1);
        Vertex[++Cnt] = U;
        Rmq[Cnt] = Depth;
    }
}

// LCA查询前的初始化，Root:根节点，NodeNum:节点数量
void LCA_Init(int Root, int NodeNum) {
    Cnt = 0;
    Dfs(Root, Root, 0);
    St.init(2 * NodeNum - 1);
}

// 查询节点U和节点V的LCA
int Query_LCA(int U, int V) {
    return Vertex[St.Query(First[U], First[V])];
}

bool Flag[maxn];

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N; Case <= T; ++Case) {
        scanf("%d", &N);
        Init();
        memset(Flag, false, sizeof(Flag));
        for (int i = 1, U, V; i < N; ++i) {
            scanf("%d%d", &U, &V);
            AddEdge(U, V);
            AddEdge(V, U);
            Flag[V] = true;
        }
        int Root;
        for (int i = 1; i <= N; ++i) {
            if (!Flag[i]) {
                Root = i;
                break;
            }
        }
        LCA_Init(Root, N);
        int QueryU, QueryV;
        scanf("%d%d", &QueryU, &QueryV);
        printf("%d\n", Query_LCA(QueryU, QueryV));
    }
    return 0;
}

