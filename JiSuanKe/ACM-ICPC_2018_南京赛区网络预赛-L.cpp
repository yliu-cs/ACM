#include <bits/stdc++.h>

const int maxn = 1e5 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct Link {
    long long V, Weight, Next;
    Link(long long _V = 0, long long _Weight = 0, long long _Next = 0): V(_V), Weight(_Weight), Next(_Next) {}
};

Link edges[(maxn << 2) * 12];
int Head[maxn * 12];
int Tot;
long long Dis[maxn * 12];

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(long long U, long long V, long long Weight) {
    edges[Tot] = Link (V, Weight, Head[U]);
    Head[U] = Tot++;
}

struct Cmp {
    bool operator() (const int &A, const int &B) {
        return Dis[A] > Dis[B];
    }
};

int T;
int N, M, K;
long long Ans;

void Dijkstra(int Start) {
    std::priority_queue<int, std::vector<int>, Cmp> Que;
    memset(Dis, INF, sizeof(Dis));
    Dis[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int U = Que.top(); Que.pop();
        for (int i = Head[U]; i != -1; i = edges[i].Next) {
            Link &Temp = edges[i];
            if (Dis[Temp.V] > Dis[U] + Temp.Weight) {
                Dis[Temp.V] = Dis[U] + Temp.Weight;
                Que.push(Temp.V);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        Init();
        scanf("%d%d%d", &N, &M, &K);
        for (long long i = 0, U, V, C; i < M; ++i) {
            scanf("%lld%lld%lld", &U, &V, &C);
            for (int j = 0; j <= K; ++j) {
                AddEdge(U + j * N, V + j * N, C);
                if (j != K) {
                    AddEdge(U + j * N, V + (j + 1) * N, 0);
                }
            }
        }
        Dijkstra(1);
        Ans = INF;
        for (int i = 0; i <= K; ++i) {
            Ans = std::min(Ans, Dis[N + i * N]);
        }
        printf("%lld\n", Ans);
    }
    return 0;
}

