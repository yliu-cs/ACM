#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)(1e5 + 5);

struct Edge {int V, Next;};

int Tot;
int Head[maxn];
Edge edges[maxn << 1];

void AddEdge(int U, int V) {
    edges[Tot] = (Edge){V, Head[U]};
    Head[U] = Tot++;
    edges[Tot] = (Edge){U, Head[V]};
    Head[V] = Tot++;
}

int N;
int A[maxn];
int Dep[maxn];
int Cnt[maxn];
int Suffix[maxn];
int MaxDep;
int Ans;

void Dfs(int Cur, int Pre, int Depth) {
    MaxDep = max(MaxDep, Depth);
    Dep[Cur] = Depth;
    if (A[Cur] == 1) Cnt[Depth]++;
    for (int i = Head[Cur]; ~i; i = edges[i].Next) {
        if (edges[i].V == Pre) continue;
        Dfs(edges[i].V, Cur, Depth + 1);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    Tot = 0;
    for (int i = 1; i <= N; ++i) Head[i] = -1;
    for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
    for (int i = 1, U, V; i < N; ++i) {
        scanf("%d%d", &U, &V);
        AddEdge(U, V);
    }
    Dfs(1, 0, 0);
    for (int i = MaxDep; i >= 0; --i) Suffix[i] = Suffix[i + 1] + Cnt[i];
    for (int i = 1; i <= N; ++i) Ans = max(Ans, Dep[i] + Suffix[Dep[i]] - 1);
    printf("%d\n", Ans);
    return 0;
}
