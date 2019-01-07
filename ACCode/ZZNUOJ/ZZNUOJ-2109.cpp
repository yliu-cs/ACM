#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;

struct Link {
    long long V, Cap, Cost, Flow, Next;
};

int N;
int A[maxn], B[maxn];
int Head[maxn];
int Path[maxn];
int Dis[maxn];
bool Vis[maxn];
int Tot;
Link edges[maxn << 7];

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V, long long Cap, long long Cost) {
    edges[Tot] = Link {V, Cap, Cost, 0, Head[U]};
    Head[U] = Tot++;
    edges[Tot] = Link {U, 0, -Cost, 0, Head[V]};
    Head[V] = Tot++;
}

bool Spfa(int Start, int End) {
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

int MinCostMaxFlow(int Start, int End, long long &MinCost) {
    int MaxFlow = 0;
    MinCost = 0;
    while (Spfa(Start, End)) {
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
    while (~scanf("%d", &N)) {
        Init();
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &A[i]);
            AddEdge(0, i, A[i], 0);
        }
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &B[i]);
            AddEdge(i, N + 1, B[i], 0);
        }
        for (int i = 1, U, V, C; i < N; ++i) {
            scanf("%d%d%d", &U, &V, &C);
            AddEdge(U, V, INF, C);
            AddEdge(V, U, INF, C);
        }
        long long MinCost;
        MinCostMaxFlow(0, N + 1, MinCost);
        printf("%lld\n", MinCost);
    }
    return 0;
}
