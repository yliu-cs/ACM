#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
const int maxn = 3e5 + 5;

struct Edge {
    int V, Next;
};

Edge edges[maxn << 4];
int Head[maxn];
int Tot;

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
        int Len = (int)(log2(B - A + 1));
        return Rmq[Dp[A][Len]] < Rmq[Dp[B - (1 << Len) + 1][Len]] ? Dp[A][Len] : Dp[B - (1 << Len) + 1][Len];
    }
};

int Vertex[maxn << 1];
int First[maxn];
int Cnt;
ST St;
int Parent[maxn];

void LCADfs(int Cur, int Pre, int Depth) {
    Vertex[++Cnt] = Cur;
    First[Cur] = Cnt;
    Rmq[Cnt] = Depth;
    Parent[Cur] = Pre;
    for (int i = Head[Cur]; ~i; i = edges[i].Next) {
        if (edges[i].V == Pre) {
            continue;
        }
        LCADfs(edges[i].V, Cur, Depth + 1);
        Vertex[++Cnt] = Cur;
        Rmq[Cnt] = Depth;
    }
}

void LCAInit(int N) {
    Cnt = 0;
    LCADfs(1, 0, 0);
    St.Init(2 * N - 1);
}

int QueryLCA(int U, int V) {
    return Vertex[St.Query(First[U], First[V])];
}

long long Factorial[maxn];
long long InvFactorial[maxn];

long long QuickPow(long long A, long long B) {
    long long Ans = 1;
    while (B) {
        if (B & 1) {
            Ans = Ans * A % mod;
        }
        A = A * A % mod;
        B >>= 1;
    }
    return Ans;
}

void FactorialInit(int N) {
    Factorial[0] = 1;
    for (long long i = 1; i <= N; ++i) {
        Factorial[i] = (Factorial[i - 1] * i) % mod;
    }
    InvFactorial[N] = QuickPow(Factorial[N], mod - 2);
    for (long long i = N - 1; ~i; --i) {
        InvFactorial[i] = (InvFactorial[i + 1] * (i + 1)) % mod;
    }
}

long long C(int N, int M) {
    if (M > N || M < 0 || N < 0) {
        return 0;
    }
    return Factorial[N] * InvFactorial[M] % mod * InvFactorial[N - M] % mod;
}

int Count[maxn];
int LCACount[maxn];

int T;
int N, M, K;
long long Ans;

int Dfs(int Cur, int Pre) {
    for (int i = Head[Cur]; ~i; i = edges[i].Next) {
        if (edges[i].V == Pre) {
            continue;
        }
        Count[Cur] += Dfs(edges[i].V, Cur);
    }
    if (LCACount[Cur]) {
        Ans += ((C(Count[Cur], K) - C(Count[Cur] - LCACount[Cur], K)) + mod) % mod;
        Ans %= mod;
    }
    return Count[Cur];
}

void Init(int N) {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
    for (int i = 1; i <= N; ++i) {
        Count[i] = 0;
        LCACount[i] = 0;
    }
}

int main(int argc, char *argv[]) {
    FactorialInit(maxn - 5);
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d%d%d", &N, &M, &K);
        Init(N);
        for (int i = 1, U, V; i < N; ++i) {
            scanf("%d%d", &U, &V);
            AddEdge(U, V);
            AddEdge(V, U);
        }
        Parent[1] = 0;
        LCAInit(N);
        for (int i = 1, U, V; i <= M; ++i) {
            scanf("%d%d", &U, &V);
            int LCA = QueryLCA(U, V);
            LCACount[LCA]++;
            Count[U]++; Count[V]++;
            Count[LCA]--; Count[Parent[LCA]]--;
        }
        Ans = 0;
        Dfs(1, 0);
        printf("%lld\n", Ans);
    }
    return 0;
}

