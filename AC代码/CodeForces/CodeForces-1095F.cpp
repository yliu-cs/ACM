
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;

struct Edge {
    int U, V;
    long long Dis;

    bool operator < (const Edge &B) const {
        return Dis < B.Dis;
    }
};

int N, M;
int Tot;
int Pre[maxn];
Edge edges[maxn << 4];

void Init() {
    for (int i = 0; i <= N; ++i) {
        Pre[i] = i;
    }
}

int Find(int X) {
    int R = X;
    while (Pre[R] != R) {
        R = Pre[R];
    }
    int I = X, J;
    while (I != R) {
        J = Pre[I];
        Pre[I] = R;
        I = J;
    }
    return R;
}

void Join(int X, int Y) {
    int XX = Find(X);
    int YY = Find(Y);
    if (XX != YY) {
        Pre[XX] = YY;
    }
}

long long Kruskal() {
    sort(edges, edges + Tot);
    Init();
    long long Res = 0;
    for (int i = 0; i < Tot; ++i) {
        Edge Temp = edges[i];
        if (Find(Temp.U) != Find(Temp.V)) {
            Join(Temp.U, Temp.V);
            Res += Temp.Dis;
        }
    }
    return Res;
}

long long Vertex[maxn];
int Min;

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    Min = 1;
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", &Vertex[i]);
        if (Vertex[i] < Vertex[Min]) {
            Min = i;
        }
    }
    Tot = 0;
    for (int i = 1; i <= N; ++i) {
        edges[Tot++] = Edge {i, Min, Vertex[i] + Vertex[Min]};
    }
    for (int i = 1, U, V; i <= M; ++i) {
        long long Coin;
        scanf("%d%d%lld", &U, &V, &Coin);
        edges[Tot++] = Edge{U, V, Coin};
    }
    printf("%lld\n", Kruskal());
    return 0;
}

