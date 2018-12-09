#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 5;

struct Edge {
    int V, Next;
};

Edge edges[maxn << 1];
int Head[maxn];
int Tot;

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V) {
    edges[Tot] = Edge {V, Head[U]};
    Head[U] = Tot++;
}

int Rmq[maxn << 1];

struct ST {
    int Dp[maxn << 1][20];
    void Init(int N) {
        for (int i = 1; i <= N; ++i) {
            Dp[i][0] = i;
        }
        for (int j = 1; (1 << j) <= N; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= N; ++i) {
                Dp[i][j] = Rmq[Dp[i][j - 1]] < Rmq[Dp[i + (1 << (j - 1))][j - 1]] ? Dp[i][j - 1] : Dp[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    int Query(int A, int B) {
        if (A > B) {
            swap(A, B);
        }
        int Len = int(log2(B - A + 1));
        return Rmq[Dp[A][Len]] <= Rmq[Dp[B - (1 << Len) + 1][Len]] ? Dp[A][Len] : Dp[B - (1 << Len) + 1][Len];
    }
};

int Vertex[maxn << 1];
int First[maxn];
int Parent[maxn];
int LCATot;
ST St;

void LCADfs(int Cur, int Pre, int Depth) {
    Vertex[++LCATot] = Cur;
    First[Cur] = LCATot;
    Rmq[LCATot] = Depth;
    Parent[Cur] = Pre;
    for (int i = Head[Cur]; ~i; i = edges[i].Next) {
        if (edges[i].V == Pre) {
            continue;
        }
        LCADfs(edges[i].V, Cur, Depth + 1);
        Vertex[++LCATot] = Cur;
        Rmq[LCATot] = Depth;
    }
}

void LCAInit(int Root, int NodeNum) {
    LCATot = 0;
    LCADfs(Root, 0, 0);
    St.Init(2 * NodeNum - 1);
}

int QueryLCA(int U, int V) {
    return Vertex[St.Query(First[U], First[V])];
}

int N, K;
int Ans;
int Cnt[maxn];

int Dfs(int Cur, int Pre) {
    for (int i = Head[Cur]; ~i; i = edges[i].Next) {
        if (edges[i].V == Pre) {
            continue;
        }
        Cnt[Cur] += Dfs(edges[i].V, Cur);
    }
    Ans = max(Ans, Cnt[Cur]);
    return Cnt[Cur];
}

int main(int argc, char *argv[]) {
    Init();
    scanf("%d%d", &N, &K);
    for (int i = 1, X, Y; i < N; ++i) {
        scanf("%d%d", &X, &Y);
        AddEdge(X, Y);
        AddEdge(Y, X);
    }
    memset(Parent, 0, sizeof(Parent));
    LCAInit(1, N);
    memset(Cnt, 0, sizeof(Cnt));
    for (int i = 1, S, T; i <= K; ++i) {
        scanf("%d%d", &S, &T);
        int LCA = QueryLCA(S, T);
        Cnt[S]++; Cnt[T]++;
        Cnt[LCA]--; Cnt[Parent[LCA]]--;
    }
    Ans = 0;
    Dfs(1, 0);
    printf("%d\n", Ans);
    return 0;
}

