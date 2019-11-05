#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 5;

struct Edge {
    int V, Next, Cap, Flow, Cost;
    Edge(int _V = 0, int _Next = 0, int _Cap = 0, int _Flow = 0, int _Cost = 0): V(_V), Next(_Next), Cap(_Cap), Flow(_Flow), Cost(_Cost) {}
};

int Head[maxn];
int Path[maxn];
int Dis[maxn];
bool Vis[maxn];
int Tot;
Edge edges[maxn << 4];

int N, M, K;
int Ans;
bool Flag;
int DemandSum;

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V, int Cap, int Cost) {
    edges[Tot].V = V;
    edges[Tot].Cap = Cap;
    edges[Tot].Cost = Cost;
    edges[Tot].Flow = 0;
    edges[Tot].Next = Head[U];
    Head[U] = Tot++;
    edges[Tot].V = U;
    edges[Tot].Cap = 0;
    edges[Tot].Cost = -Cost;
    edges[Tot].Flow = 0;
    edges[Tot].Next = Head[V];
    Head[V] = Tot++;
}

bool SPFA(int Start, int End) {
    memset(Dis, INF, sizeof(Dis));
    memset(Vis, false, sizeof(Vis));
    memset(Path, -1, sizeof(Path));
    Dis[Start] = 0;
    Vis[Start] = true;
    std::queue<int> Que;
    while (!Que.empty()) {
        Que.pop();
    }
    Que.push(Start);
    while (!Que.empty()) {
        int U = Que.front();
        Que.pop();
        Vis[U] = false;
        for (int i = Head[U]; i != -1; i = edges[i].Next) {
            int V = edges[i].V;
            if (edges[i].Cap > edges[i].Flow && Dis[V] > Dis[U] + edges[i].Cost) {
                Dis[V] = Dis[U] + edges[i].Cost;
                Path[V] = i;
                if (!Vis[V]) {
                    Vis[V] = true;
                    Que.push(V);
                }
            }
        }
    }
    return Path[End] != -1;
}

int MinCostMaxFlow(int Start, int End, int &MinCost) {
    int MaxFlow = 0;
    MinCost = 0;
    while (SPFA(Start, End)) {
        int Min = INF;
        for (int i = Path[End]; i != -1; i = Path[edges[i ^ 1].V]) {
            if (edges[i].Cap - edges[i].Flow < Min) {
                Min = edges[i].Cap - edges[i].Flow;
            }
        }
        for (int i = Path[End]; i != -1; i = Path[edges[i ^ 1].V]) {
            edges[i].Flow += Min;
            edges[i ^ 1].Flow -= Min;
            MinCost += edges[i].Cost * Min;
        }
        MaxFlow += Min;
    }
    return MaxFlow;
}

int main(int argc, char *argv[]) {
    while (~scanf("%d%d%d", &N, &M, &K) && (N + M + K)) {
        Flag = true;
        std::vector<std::vector<int> > Demand(N + 1);
        for (int i = 1; i <= N; ++i) {
            for (int j = 1, X; j <= K; ++j) {
                scanf("%d", &X);
                Demand[i].push_back(X);
            }
        }
        std::vector<std::vector<int> > Supply(M + 1);
        for (int i = 1; i <= M; ++i) {
            for (int j = 1, X; j <= K; ++j) {
                scanf("%d", &X);
                Supply[i].push_back(X);
            }
        }
        Ans = 0;
        for (int i = 1; i <= K; ++i) {
            Init();
            DemandSum = 0;
            for (int j = 1; j <= N; ++j) {
                AddEdge(0, j, Demand[j][i - 1], 0);
                DemandSum += Demand[j][i - 1];
                for (int k = 1, X; k <= M; ++k) {
                    scanf("%d", &X);
                    AddEdge(j, N + k, INF, X);
                    if (j == 1) {
                        AddEdge(N + k, N + M + 1, Supply[k][i - 1], 0);
                    }
                }
            }
            int TempCost, MaxFlow;
            MaxFlow = MinCostMaxFlow(0, N + M + 1, TempCost);
            if (MaxFlow != DemandSum) {
                Flag = false;
            }
            Ans += TempCost;
        }
        Ans = !Flag ? -1 : Ans;
        printf("%d\n", Ans);
    }
    return 0;
}

