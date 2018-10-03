#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 5;

struct Link {
    int V, Weight, Next;
    Link(int _V = 0, int _Weight = 0, int _Next = 0): V(_V), Weight(_Weight), Next(_Next) {}
};

// 一定要开的超大...不然TLE
Link edges[maxn << 2];
int Head[maxn << 1];
int Tot;
int Depth[maxn << 1];
int Current[maxn << 1];
int T;
int N, M, D;
int Ans;
int Cnt;
char Height[maxn][maxn];
char Maze[maxn][maxn];

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
        for (int i = 0; i <= N * M * 2 + 1; ++i) {
            Current[i] = Head[i];
        }
        MaxFlow += Dfs(Start, End, INF);
    }
    return MaxFlow;
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        Init();
        scanf("%d%d", &N, &D);
        for (int i = 1; i <= N; ++i) {
            scanf("%s", Height[i]);
            getchar();
        }
        M = strlen(Height[1]);
        for (int i = 1; i <= N; ++i) {
            scanf("%s", Maze[i]);
            getchar();
        }
        Cnt = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                int Num = M * (i - 1) + j;
                AddEdge(Num, N * M + Num, (Height[i][j - 1] - '0'));
                if (Maze[i][j - 1] == 'L') {
                    AddEdge(0, Num, 1);
                    Cnt++;
                }
                bool flag = 0;
                for (int k = i - D; k <= i + D; ++k) {
                    for (int l = j - D; l <= j + D; ++l) {
                        if (k == i && l == j) {
                            continue;
                        }
                        if (k > 0 && k <= N && l > 0 && l <= M) {
                            if (abs(k - i) + abs(l - j) <= D) {
                                AddEdge(N * M + Num, M * (k - 1) + l, INF);
                            }
                        }
                        else if (abs(k - i) + abs(l - j) <= D) {
                            if (!flag) {
                                AddEdge(N * M + Num, N * M * 2 + 1, INF);
                                flag = 1;
                            }
                        }
                    }
                }
            }
        }
        Ans = Cnt - Dinic(0, N * M * 2 + 1);
        if (Ans == 0) {
            printf("Case #%d: no lizard was left behind.\n", Case);
        }
        else if (Ans == 1) {
            printf("Case #%d: %d lizard was left behind.\n", Case, Ans);
        }
        else {
            printf("Case #%d: %d lizards were left behind.\n", Case, Ans);
        }
    }
    return 0;
}

