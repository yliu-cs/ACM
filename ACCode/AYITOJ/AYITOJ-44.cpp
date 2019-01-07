#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

struct Edge {
    long long V, Dis, Next;
};

Edge edges[maxn << 4];
int Head[maxn << 1];
int Tot;

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V, long long Weight) {
    edges[Tot] = Edge {V, Weight, Head[U]};
    Head[U] = Tot++;
}

long long Dis[maxn << 1];

struct Cmp {
    bool operator () (const int &A, const int &B) {
        return Dis[A] > Dis[B];
    }
};

long long Dijkstra(int Start, int End) {
    priority_queue<int, vector<int>, Cmp> Que;
    memset(Dis, 0x3f, sizeof(Dis));
    Dis[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int Cur = Que.top(); Que.pop();
        if (Cur == End) {
            return Dis[End];
        }
        for (int i = Head[Cur]; ~i; i = edges[i].Next) {
            if (Dis[edges[i].V] > Dis[Cur] + edges[i].Dis) {
                Dis[edges[i].V] = Dis[Cur] + edges[i].Dis;
                Que.push(edges[i].V);
            }
        }
    }
    return -1 * 1LL;
}

long long N, S, T;
long long U[maxn], V[maxn];
long long numbers[maxn << 1];
long long Cnt, Size;

int Disperse(long long X) {
    return lower_bound(numbers, numbers + Size, X) - numbers + 1;
}

int main(int argc, char *argv[]) {
    Init();
    scanf("%lld%lld%lld", &N, &S, &T);
    Cnt = 0;
    numbers[Cnt++] = S; numbers[Cnt++] = T;
    for (long long i = 1; i <= N; ++i) {
        scanf("%lld%lld", &U[i], &V[i]);
        numbers[Cnt++] = U[i]; numbers[Cnt++] = V[i];
    }
    sort(numbers, numbers + Cnt);
    Size = unique(numbers, numbers + Cnt) - numbers;
    for (int i = 0; i < Size - 1; ++i) {
        AddEdge(i + 1, i + 2, numbers[i + 1] - numbers[i]);
        AddEdge(i + 2, i + 1, numbers[i + 1] - numbers[i]);
    }
    for (int i = 1; i <= N; ++i) {
        AddEdge(Disperse(U[i]), Disperse(V[i]), 1);
    }
    printf("%lld\n", Dijkstra(Disperse(S), Disperse(T)));
    return 0;
}

