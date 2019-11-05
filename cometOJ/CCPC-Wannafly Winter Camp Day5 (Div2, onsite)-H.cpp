#include <bits/stdc++.h>
using namespace std;

const int mod = (int)(1e9 + 7);
const int maxn = (int)(1e6 + 5);

struct Edge {
    int V, Next;
};

int Tot;
int Head[maxn];
Edge edges[maxn << 1];

void AddEdge(int U, int V) {
    edges[Tot] = (Edge){V, Head[U]};
    Head[U] = Tot++;
    edges[Tot] = (Edge){U, Head[V]};
    Head[V] = Tot++;
}

int N, M;
long long Dp[maxn];
long long Ans;

long long Dfs(int Cur, int Pre) {
    Dp[Cur] = 1;
    for (int i = Head[Cur]; ~i; i = edges[i].Next) {
        if (edges[i].V == Pre) continue;
        Dp[Cur] += Dfs(edges[i].V, Cur);
        Ans = (Ans + (Dp[edges[i].V] * (N * M - Dp[edges[i].V])) % mod) % mod;
    }
    return Dp[Cur];
}

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    Tot = 0;
    for (int i = 1; i <= N * M; ++i) Head[i] = -1;
    for (int i = 1, U, V; i < N; ++i) {
        scanf("%d%d", &U, &V);
        for (int j = 1; j <= M; ++j) AddEdge((j - 1) * N + U, (j - 1) * N + V);
    }
    for (int i = 1, A, B, U, V; i < M; ++i) {
        scanf("%d%d%d%d", &A, &B, &U, &V);
        AddEdge((A - 1) * N + U, (B - 1) * N + V);
    }
    Ans = 0;
    Dfs(1, 0);
    printf("%lld\n", Ans);
    return 0;
}