#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;

struct Edge {
    long long V, Dis, Next;
};

Edge edges[maxn << 7];
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

void Dijkstra(int Start) {
    priority_queue<int, vector<int>, Cmp> Que;
    memset(Dis, INF, sizeof(Dis));
    Dis[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int Cur = Que.top(); Que.pop();
        for (int i = Head[Cur]; ~i; i = edges[i].Next) {
            if (Dis[edges[i].V] > Dis[Cur] + edges[i].Dis) {
                Dis[edges[i].V] = Dis[Cur] + edges[i].Dis;
                Que.push(edges[i].V);
            }
        }
    }
}

long long N, S, T;
long long U[maxn], V[maxn];
vector<long long> numbers;

int Disperse(long long X) {
    return lower_bound(numbers.begin(), numbers.end(), X) - numbers.begin() + 1;
}

int main(int argc, char *argv[]) {
    Init();
    scanf("%lld%lld%lld", &N, &S, &T);
    numbers.push_back(S); numbers.push_back(T);
    for (long long i = 1; i <= N; ++i) {
        scanf("%lld%lld", &U[i], &V[i]);
        numbers.push_back(U[i]); numbers.push_back(V[i]);
    }
    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
    for (int i = 0; i < int(numbers.size()) - 1; ++i) {
        AddEdge(i + 1, i + 2, numbers[i + 1] - numbers[i]);
        AddEdge(i + 2, i + 1, numbers[i + 1] - numbers[i]);
    }
    for (int i = 1; i <= N; ++i) {
        AddEdge(Disperse(U[i]), Disperse(V[i]), 1);
    }
    Dijkstra(Disperse(S));
    printf("%lld\n", Dis[Disperse(T)]);
    return 0;
}

