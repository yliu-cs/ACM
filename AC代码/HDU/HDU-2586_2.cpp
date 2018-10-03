#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

struct Link {
    int V, Weight, Next;
    Link(int _V = 0, int _Weight = 0, int _Next = 0): V(_V), Weight(_Weight), Next(_Next) {}
};

int T;
int N, M;
Link edges[maxn << 1];
int Head[maxn];
int Tot;
int Dis[maxn];

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V, int Weight) {
    edges[Tot] = Link (V, Weight, Head[U]);
    Head[U] = Tot++;
}

struct Cmp {
    bool operator() (const int &A, const int &B) {
        return Dis[A] > Dis[B];
    }
};

void Dijkstra(int Start) {
    std::priority_queue<int, std::vector<int>, Cmp> Que;
    memset(Dis, INF, sizeof(Dis));
    Dis[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int U = Que.top(); Que.pop();
        for (int i = Head[U]; ~i; i = edges[i].Next) {
            if (Dis[edges[i].V] > Dis[U] + edges[i].Weight) {
                Dis[edges[i].V] = Dis[U] + edges[i].Weight;
                Que.push(edges[i].V);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        Init();
        scanf("%d%d", &N, &M);
        for (int i = 1, U, V, C; i < N; ++i) {
            scanf("%d%d%d", &U, &V, &C);
            AddEdge(U, V, C);
            AddEdge(V, U, C);
        }
        for (int Query = 1, U, V; Query <= M; ++Query) {
            scanf("%d%d", &U, &V);
            Dijkstra(U);
            printf("%d\n", Dis[V]);
        }
    }
    return 0;
}

