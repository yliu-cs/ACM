#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const int maxn = 2e2 + 5;

struct Link {
    int V, Weight, Next;
    Link(int _V = 0, int _Weight = 0, int _Next = 0): V(_V), Weight(_Weight), Next(_Next) {}
};

Link edges[maxn * maxn * 2];
int Head[maxn * maxn * 2];
int Tot;
int Depth[maxn * maxn * 2];
int Current[maxn * maxn * 2];

int Pre[maxn];

int TCase;
int N, M, F;
bool Relation[maxn][maxn];

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V, int Weight, int ReverseWeight = 0) {
    edges[Tot].V = V;
    edges[Tot].Weight = Weight;
    edges[Tot].Next = Head[U];
    Head[U] = Tot++;
    edges[Tot].V = U;
    edges[Tot].Weight = ReverseWeight;
    edges[Tot].Next = Head[V];
    Head[V] = Tot++;
}

bool Bfs(int Start, int End) {
    memset(Depth, -1, sizeof(Depth));
    std::queue<int> Que;
    Depth[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int Vertex = Que.front();
        Que.pop();
        for (int i = Head[Vertex]; i != -1; i = edges[i].Next) {
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
    for (int &i = Current[Vertex]; i != -1; i = edges[i].Next) {
        if (edges[i].Weight > 0 && Depth[edges[i].V] == Depth[Vertex] + 1) {
            FindFlow = Dfs(edges[i].V, End, std::min(NowFlow - UsableFlow, edges[i].Weight));
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

int Dinic(int Start, int End) {
    int MaxFlow = 0;
    while (Bfs(Start, End)) {
        for (int i = 0; i <= N + N + 1; ++i) {
            Current[i] = Head[i];
        }
        MaxFlow += Dfs(Start, End, INF);
    }
    return MaxFlow;
}

int Find(int X) {
    int R = X;
    while (Pre[R] != R) {
        R = Pre[R];
    }
    return R;
}

void Join(int X, int Y) {
    int XX = Find(X);
    int YY = Find(Y);
    if (XX != YY) {
        Pre[XX] = YY;
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &TCase);
    for (int Case = 1; Case <= TCase; ++Case) {
        memset(Relation, false, sizeof(Relation));
        scanf("%d%d%d", &N, &M, &F);
        for (int i = 1; i <= N; ++i) {
            Pre[i] = i;
        }
        for (int i = 1, A, B; i <= M; ++i) {
            scanf("%d%d", &A, &B);
            Relation[A][N + B] = true;
        }
        for (int i = 1, C, D; i <= F; ++i) {
            scanf("%d%d", &C, &D);
            Join(C, D);
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                if (Find(i) == Find(j)) {
                    for (int k = N + 1; k <= N + N; ++k) {
                        Relation[i][k] = Relation[j][k] = (Relation[i][k] || Relation[j][k]);
                    }
                }
            }
        }
        int Left = 0, Right = 1e5;
        while (Left < Right) {
            int Mid = Left + (Right - Left + 1) / 2;
            Init();
            for (int i = 1; i <= N; ++i) {
                AddEdge(0, i, Mid);
                for (int j = N + 1; j <= N + N; ++j) {
                    if (i == 1) {
                        AddEdge(j, N + N + 1, Mid);
                    }
                    if (Relation[i][j]) {
                        AddEdge(i, j, 1);
                    }
                }
            }
            if (N * Mid == Dinic(0, N + N + 1)) {
                Left = Mid;
            }
            else {
                Right = Mid - 1;
            }
        }
        printf("%d\n", Left);
    }
    return 0;
}
