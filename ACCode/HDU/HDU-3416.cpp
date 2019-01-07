#include <bits/stdc++.h>
typedef std::pair<int,int> PII;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

struct Edge {
    int V, Dis;
    Edge(int _V = 0, int _Dis = 0): V(_V), Dis(_Dis) {}
};

struct Link {
    int V, Weight, Next;
    Link(int _V = 0, int _Weight = 0, int _Next = 0): V(_V), Weight(_Weight), Next(_Next) {}
};

int TCase;
int N, E;

int Dis[maxn];
std::vector<Edge> Adj[maxn];

Link edges[1000005];
int Head[maxn];
int Tot;
int Depth[maxn];
int Current[maxn];

void Addedge(int U, int V, int Weight) {
    Adj[U].push_back(Edge {V, Weight});
}

void Dijkstra(int Start, int End) {
    std::priority_queue<PII, std::vector<PII>, std::greater<PII> > Que;
    memset(Dis, INF, sizeof(Dis));
    Dis[Start] = 0;
    Que.push(std::make_pair(0, Start));
    while (!Que.empty()) {
        PII Keep = Que.top();
        Que.pop();
        int V = Keep.second;
        if (Dis[V] < Keep.first) {
            continue;
        }
        for (int i = 0; i <int(Adj[V].size()); ++i) {
            Edge Temp = Adj[V][i];
            if (Dis[Temp.V] > Dis[V] + Temp.Dis) {
                Dis[Temp.V] = Dis[V] + Temp.Dis;
                Que.push(std::make_pair(Dis[Temp.V], Temp.V));
            }
        }
    }
}

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
        for (int i = 1; i <= N; ++i) {
            Current[i] = Head[i];
        }
        MaxFlow += Dfs(Start, End, INF);
    }
    return MaxFlow;
}

int main(int argc, char *argv[]) {
    scanf("%d", &TCase);
    for (int Case = 1, S, T; Case <= TCase; ++Case) {
        Init();
        scanf("%d%d", &N, &E);
        for (int i = 1; i <= N; ++i) {
            Adj[i].clear();
        }
        std::vector<int> U(E + 1, 0), V(E + 1, 0), C(E + 1, 0);
        for (int i = 1; i <= E; ++i) {
            scanf("%d%d%d", &U[i], &V[i], &C[i]);
            Addedge(U[i], V[i], C[i]);
        }
        scanf("%d%d", &S, &T);
        Dijkstra(S, T);
        if (Dis[T] == INF) {
            printf("%d\n", 0);
            continue;
        }
        for (int i = 1; i <= E; ++i) {
            if (Dis[U[i]] + C[i] == Dis[V[i]]) {
                AddEdge(U[i], V[i], 1);
            }
        }
        printf("%d\n", Dinic(S, T));
    }
    return 0;
}

