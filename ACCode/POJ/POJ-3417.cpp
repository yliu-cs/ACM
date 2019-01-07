#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 1e6 + 5;

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

struct LCAOnline {
    int Rmq[maxn << 1];
    int Vertex[maxn << 1];
    int First[maxn];
    int Parent[maxn];
    int LCATot;
    
    int Dp[maxn << 1][20];
    
    void Work(int N) {
        for (int i = 1; i <= N; ++i) {
            Dp[i][0] = i;
        }
        for (int j = 1; (1 << j) <= N; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= N; ++i) {
                Dp[i][j] = Rmq[Dp[i][j - 1]] < Rmq[Dp[i + (1 << (j - 1))][j - 1]] ? Dp[i][j - 1] : Dp[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    void Dfs(int Cur, int Pre, int Depth) {
        Vertex[++LCATot] = Cur;
        First[Cur] = LCATot;
        Rmq[LCATot] = Depth;
        Parent[Cur] = Pre;
        for (int i = Head[Cur]; ~i; i = edges[i].Next) {
            if (edges[i].V == Pre) {
                continue;
            }
            Dfs(edges[i].V, Cur, Depth + 1);
            Vertex[++LCATot] = Cur;
            Rmq[LCATot] = Depth;
        }
    }
    
    int Query(int Left, int Right) {
        if (Left > Right) {
            swap(Left, Right);
        }
        int Len = int(log2(Right - Left + 1));
        return Rmq[Dp[Left][Len]] <= Rmq[Dp[Right - (1 << Len) + 1][Len]] ? Dp[Left][Len] : Dp[Right - (1 << Len) + 1][Len];
    }
    
    void Init(int Root, int NodeNum) {
        LCATot = 0;
        Dfs(Root, 0, 0);
        Parent[1] = 0;
        Work(2 * NodeNum - 1);
    }

    int LCA(int U, int V) {
        return Vertex[Query(First[U], First[V])];
    }
}LCA;

int N, M;
int Ans;
int Cnt[maxn];

int Dfs(int Cur, int Pre) {
    for (int i = Head[Cur]; ~i; i = edges[i].Next) {
        if (edges[i].V == Pre) {
            continue;
        }
        Cnt[Cur] += Dfs(edges[i].V, Cur);
    }
    return Cnt[Cur];
}

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    Init();
    for (int i = 1, U, V; i < N; ++i) {
        scanf("%d%d", &U, &V);
        AddEdge(U, V);
        AddEdge(V, U);
    }
    LCA.Init(1, N);
    memset(Cnt, 0, sizeof(Cnt));
    for (int i = 1, U, V; i <= M; ++i) {
        scanf("%d%d", &U, &V);
        Cnt[U]++; Cnt[V]++;
        Cnt[LCA.LCA(U, V)] -= 2;
    }
    Dfs(1, 0);
    Ans = 0;
    for (int i = 2; i <= N; ++i) {
        if (Cnt[i] == 0) {
            Ans += M;
        }
        else if (Cnt[i] == 1) {
            Ans++;
        }
    }
    printf("%d\n", Ans);
    return 0;
}

