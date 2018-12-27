#include <bits/stdc++.h>

const int maxn = "Edit";

struct Edge {
    int U, V, Dis;

    bool operator < (const Edge &B) const {
        return Dis < B.Dis;
    }
};

// N:顶点数，E:边数，Pre并查集
int N, E, Pre[maxn];
// edges:边
Edge edges[maxn];

void Init() {
    // 并查集初始化
    for (int i = 0; i <= N; ++i) {
        Pre[i] = i;
    }
}

// 并查集查询
int Find(int X) {
    int R = X;
    while (Pre[R] != R) {
        R = Pre[R];
    }
    int I = X, J;
    while (I != R) {
        J = Pre[I];
        Pre[I] = R;
        I = J;
    }
    return R;
}

// 并查集合并
void Join(int X, int Y) {
    int XX = Find(X);
    int YY = Find(Y);
    if (XX != YY) {
        Pre[XX] = YY;
    }
}

// Kruskal算法
int Kruskal() {
    // 贪心排序
    std::sort(edges + 1, edges + E + 1);
    Init();
    int Res = 0;
    // 选边计算
    for (int i = 1; i <= E; ++i) {
        Edge Temp = edges[i];
        if (Find(Temp.U) != Find(Temp.V)) {
            Join(Temp.U, Temp.V);
            Res += Temp.Dis;
        }
    }
    return Res;
}
