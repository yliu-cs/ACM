#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

struct Edge {
    int V;
    long long Weight;
    int Next;
};

int Tot;
int Head[maxn];
Edge edges[maxn << 2];


void AddEdge(int U, int V, long long Weight) {
    edges[Tot] = (Edge){V, Weight, Head[U]};
    Head[U] = Tot++;
}

int N, M, K;
int X, Y;
long long Z;
long long Height[maxn];

struct Status {
    long long Pos, Power, Cost, Reduce;

    bool operator < (const Status &Key) const {
        if (Cost == Key.Cost) {
            return Power < Key.Power;
        }
        return Cost > Key.Cost;
    }
};

long long Cost[maxn];

bool Check(int Pos, long long PreCost) {
    if  (Cost[Pos] != -1) {
        if (PreCost < Cost[Pos]) {
            return true;
        }
        return false;
    }
    return true;
}

long long Bfs() {
    priority_queue<Status> Que;
    for (int i = 1; i <= N; ++i) {
        Cost[i] = -1;
    }
    Que.push((Status){1, K, 0, 0});
    while (!Que.empty()) {
        Status Cur = Que.top(); Que.pop();
        if (Cur.Pos == N) {
            return Cur.Cost;
        }
        for (int i = Head[Cur.Pos]; ~i; i = edges[i].Next) {
            long long Diff = Height[edges[i].V] - (Height[Cur.Pos] - Cur.Reduce);
            if (Diff < 0) {
                if (Check(edges[i].V, Cur.Cost + edges[i].Weight)) {
                    Que.push((Status){edges[i].V, Cur.Power - Diff, Cur.Cost + edges[i].Weight, 0});
                    Cost[edges[i].V] = Cur.Cost + edges[i].Weight;
                }
            }
            else if (Diff <= Cur.Power) {
                if (Check(edges[i].V, Cur.Cost + edges[i].Weight)) {
                    Que.push((Status) {edges[i].V, Cur.Power - Diff, Cur.Cost + edges[i].Weight, 0});
                    Cost[edges[i].V] = Cur.Cost + edges[i].Weight;
                }
            }
            else {
                if (Check(edges[i].V, Cur.Cost + (Diff - Cur.Power) * (Diff - Cur.Power) + edges[i].Weight)) {
                    Que.push((Status){edges[i].V, 0, Cur.Cost + (Diff - Cur.Power) * (Diff - Cur.Power) + edges[i].Weight, Diff - Cur.Power});
                    Cost[edges[i].V] = Cur.Cost + (Diff - Cur.Power) * (Diff - Cur.Power) + edges[i].Weight;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d%d%d", &N, &M, &K);
    Tot = 0;
    for (int i = 1; i <= N; ++i) {
        Head[i] = -1;
    }
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", &Height[i]);
    }
    for (int i = 1; i <= M; ++i) {
        scanf("%d%d%lld", &X, &Y, &Z);
        AddEdge(X, Y, Z);
        AddEdge(Y, X, Z);
    }
    printf("%lld\n", Bfs());
    return 0;
}
