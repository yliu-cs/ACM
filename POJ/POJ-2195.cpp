#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
const int INF = 0x3f3f3f3f;
const int maxn = 5e3 + 5;

struct Edge {
    int V, Next, Cap, Flow, Cost;
    Edge(int _V = 0, int _Next = 0, int _Cap = 0, int _Flow = 0, int _Cost = 0): V(_V), Next(_Next), Cap(_Cap), Flow(_Flow), Cost(_Cost) {}
};

int Head[maxn];
int Path[maxn];
int Dis[maxn];
bool Vis[maxn];
int Tot;
Edge edges[maxn];

int N, M;
char maze[maxn][maxn];

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
    while (~scanf("%d%d", &N, &M) && N + M) {
        Init();
        std::vector<std::pair<int, int> > Man, House;
        for (int i = 1; i <= N; ++i) {
            scanf("%s", maze[i]);
            for (int j = 1; j <= M; ++j) {
                if (maze[i][j - 1] == 'm') {
                    Man.push_back(std::make_pair(i, j));
                }
                else if (maze[i][j - 1] == 'H') {
                    House.push_back(std::make_pair(i, j));
                }
            }
        }
        for (int i = 1; i <= int(Man.size()); ++i) {
            AddEdge(0, i, 1, 0);
            for (int j = 1; j <= int(House.size()); ++j) {
                if (i == 1) {
                    AddEdge(int(Man.size()) + j, int(Man.size()) + int(House.size()) + 1, 1, 0);
                }
                AddEdge(i, int(Man.size()) + j, 1, abs(Man[i - 1].first - House[j - 1].first) + abs(Man[i - 1].second - House[j - 1].second));
            }
        }
        int MinCost;
        MinCostMaxFlow(0, int(Man.size()) + int(House.size()) + 1, MinCost);
        printf("%d\n", MinCost);
    }
    return 0;
}

