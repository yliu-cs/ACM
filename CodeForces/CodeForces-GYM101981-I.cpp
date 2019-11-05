#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 5;

struct Edge {
    int V, Weight, Next;
};

Edge edges[maxn << 1];
int Head[maxn];
int Tot;
int Depth[maxn];
int Current[maxn];

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V, int Weight, int ReverseWeight = 0) {
    edges[Tot] = Edge {V, Weight, Head[U]};
    Head[U] = Tot++;

    edges[Tot] = Edge {U, ReverseWeight, Head[V]};
    Head[V] = Tot++;
}

bool Bfs(int Start, int End) {
    memset(Depth, -1, sizeof(Depth));
    queue<int> Que;
    Depth[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int Vertex = Que.front(); Que.pop();
        for (int i = Head[Vertex]; ~i; i = edges[i].Next) {
            if (Depth[edges[i].V] == -1 && edges[i].Weight > 0) {
                Depth[edges[i].V] = Depth[Vertex] + 1;
                Que.push(edges[i].V);
            }
        }
    }
    return Depth[End] != -1;
}

int Dfs(int Vertex, int End, int NowFlow) {
    if (Vertex == End || NowFlow == 0) {
        return NowFlow;
    }
    int UsableFlow = 0, FindFlow;
    for (int &i = Current[Vertex]; ~i; i = edges[i].Next) {
        if (edges[i].Weight > 0 && Depth[edges[i].V] == Depth[Vertex] + 1) {
            FindFlow = Dfs(edges[i].V, End, min(NowFlow - UsableFlow, edges[i].Weight));
            if (FindFlow > 0) {
                edges[i].Weight -= FindFlow;
                edges[i ^ 1].Weight += FindFlow;
                UsableFlow += FindFlow;
                if (UsableFlow == NowFlow) {
                    return NowFlow;
                }
            }
        }
    }
    if (!UsableFlow) {
        Depth[Vertex] = -2;
    }
    return UsableFlow;
}

int N, M, K;
int Ans;

int Dinic(int Start, int End) {
    int MaxFlow = 0;
    while (Bfs(Start, End)) {
        for (int i = 0; i <= N + M + 2; ++i) {
            Current[i] = Head[i];
        }
        MaxFlow += Dfs(Start, End, INF);
    }
    return MaxFlow;
}

int main(int argc, char *argv[]) {
    Init();
    scanf("%d%d%d", &N, &M, &K);
    AddEdge(0, N + M + 1, K);
    for (int i = 1, T; i <= N; ++i) {
        scanf("%d", &T);
        for (int j = 0, Tar; j < T; ++j) {
            scanf("%d", &Tar);
            AddEdge(i, N + Tar, 1);
        }
        AddEdge(0, i, 1);
        AddEdge(N + M + 1, i, 1);
    }
    for (int i = 1; i <= M; ++i) {
        AddEdge(N + i, N + M + 2, 1);
    }
    Ans = Dinic(0, N + M + 2);
    printf("%d\n", Ans);
    return 0;
}

