#include <bits/stdc++.h>
using namespace std;

namespace FastIO {
    const int MX = 4e7;
    char buf[MX];
    int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    template <class T>
    inline bool read(T &t) {
        while (c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) {
            c++;
        }
        if (c >= sz) {
            return false;
        }
        bool flag = 0;
        if (buf[c] == '-') {
            flag = 1;
            c++;
        }
        for (t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; ++c) {
            t = t * 10 + buf[c] - '0';
        }
        if (flag) {
            t = -t;
        }
        return true;
    }
};

const int maxn = 3e5 + 5;

struct Edge {
    int V, Weight, Next;
};

Edge edges[maxn << 1];
int Head[maxn];
int Tot;

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V, int Weight) {
    edges[Tot] = Edge {V, Weight, Head[U]};
    Head[U] = Tot++;
}

struct LCAOnline {
    int Rmq[maxn << 1];
    int Vertex[maxn << 1];
    int First[maxn];
    int Parent[maxn];
    int Dis[maxn];
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
            Dis[edges[i].V] = Dis[Cur] + edges[i].Weight;
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
        memset(Dis, 0, sizeof(Dis));
        LCATot = 0;
        Dfs(Root, 0, 0);
        Parent[1] = 0;
        Work(2 * NodeNum - 1);
    }

    int GetDis(int U, int V) {
        return Dis[U] + Dis[V] - 2 * Dis[LCA(U, V)];
    }

    int LCA(int U, int V) {
        return Vertex[Query(First[U], First[V])];
    }
}LCA;

struct Query {
    int U, V, LCA, Dis;

    bool operator < (const Query &B) const {
        return Dis < B.Dis;
    }
};

int N, M;
int Left, Right;
int Ans;
int Cnt[maxn];
Query querys[maxn];

int Dfs(int Cur, int Pre) {
    for (int i = Head[Cur]; ~i; i = edges[i].Next) {
        if (edges[i].V == Pre) {
            continue;
        }
        Cnt[Cur] += Dfs(edges[i].V, Cur);
    }
    return Cnt[Cur];
}

bool Check(int X) {
    int Num = 0, MaxDis = 0;
    memset(Cnt, 0, sizeof(Cnt));
    for (int i = 1; i <= M; ++i) {
        if (querys[i].Dis <= X) {
            continue;
        }
        Cnt[querys[i].U]++; Cnt[querys[i].V]++;
        Cnt[querys[i].LCA] -= 2;
        MaxDis = max(MaxDis, querys[i].Dis - X);
        Num++;
    }
    Dfs(1, 0);
    for (int i = 1; i <= N; ++i) {
        if (Cnt[i] == Num && LCA.GetDis(i, LCA.Parent[i]) >= MaxDis) {
            return true;
        }
    }
    return false;;
}

int main(int argc, char *argv[]) {
    FastIO::begin();
    Init();
    FastIO::read(N); FastIO::read(M);
    for (int i = 1, A, B, T; i < N; ++i) {
        FastIO::read(A); FastIO::read(B); FastIO::read(T);
        AddEdge(A, B, T);
        AddEdge(B, A, T);
    }
    LCA.Init(1, N);
    memset(Cnt, 0, sizeof(Cnt));
    Right = 0;
    for (int i = 1; i <= M; ++i) {
        FastIO::read(querys[i].U); FastIO::read(querys[i].V);
        querys[i].LCA = LCA.LCA(querys[i].U, querys[i].V);
        querys[i].Dis = LCA.GetDis(querys[i].U, querys[i].V);
        Right = max(Right, querys[i].Dis);
    }
    sort(querys + 1, querys + M + 1);
    Left = 0; Ans = 0;
    while (Left <= Right) {
        int Mid = (Left + Right) >> 1;
        if (Check(Mid)) {
            Ans = Mid;
            Right = Mid - 1;
        }
        else {
            Left = Mid + 1;
        }
    }
    printf("%d\n", Ans);
    return 0;
}

