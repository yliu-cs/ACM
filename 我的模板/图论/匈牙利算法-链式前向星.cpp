#include <bits/stdc++.h>

const int maxn = 1e5 + 5;

struct Link {
    int V, Next;
};

Link edges[maxn << 1];
int Head[maxn];
int Tot;

// 链式前向星存图初始化
void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

// 加边建图
void AddEdge(int U, int V) {
    edges[++Tot] = Link {V, Head[U]};
    Head[U] = Tot;
}

// 匹配左顶点数
int N;
// 右顶点匹配左顶点编号
int Linker[maxn];
// 右顶点匹配标记
bool Vis[maxn];

// 深度优先搜索增广路经
bool Dfs(int U) {
    for (int i = Head[U]; i != -1; i = edges[i].Next) {
        if (!Vis[edges[i].V]) {
            Vis[edges[i].V] = true;
            if (Linker[edges[i].V] == -1 || Dfs(Linker[edges[i].V])) {
                Linker[edges[i].V] = U;
                return true;
            }
        }
    }
    return false;
}

// 匈牙利算法
int Hungary() {
    int Ans = 0;
    memset(Linker, -1, sizeof(Vis));
    // 枚举左顶点
    for (int i = 1; i <= N; ++i) {
        memset(Vis, false, sizeof(Vis));
        if (Dfs(i)) {
            Ans++;
        }
    }
    return Ans;
}
