#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int maxn = 1e5 + 5;

// 链式前向星

struct Link {
    int V, Next;
};

Link edges[maxn << 1];
int Head[maxn];
int Tot = 0;

int T;
int N, M;
long long Weight[maxn];

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V) {
    edges[++Tot] = Link {V, Head[U]};
    Head[U] = Tot;
    edges[++Tot] = Link {U, Head[V]};
    Head[V] = Tot;
}

// dfs序

int Cnt;
int InIndex[maxn], OutIndex[maxn];
int Element[maxn];
long long Dis[maxn];

void Dfs(int U, int Pre) {
    Cnt++;
    InIndex[U] = Cnt;
    Element[Cnt] = U;
    for (int i = Head[U]; i != -1; i = edges[i].Next) {
        if (edges[i].V != Pre) {
            Dis[edges[i].V] = Dis[U] + Weight[edges[i].V];
            Dfs(edges[i].V, U);
        }
    }
    OutIndex[U] = Cnt;
}

// 线段树

long long Max[maxn << 2], Lazy[maxn << 2];

void PushUp(int Root) {
    Max[Root] = max(Max[Root << 1], Max[Root << 1 | 1]);
}

void PushDown(int Root) {
    if (Lazy[Root]) {
        Lazy[Root << 1] += Lazy[Root];
        Lazy[Root << 1 | 1] += Lazy[Root];
        Max[Root << 1] += Lazy[Root];
        Max[Root << 1 | 1] += Lazy[Root];
        Lazy[Root] = 0;
    }
}

void Build(int Left, int Right, int Root) {
    Lazy[Root] = 0;
    if (Left == Right) {
        Max[Root] = Dis[Element[Left]];
        return;
    }
    int Mid = (Left + Right) >> 1;
    Build(Left, Mid, Root << 1);
    Build(Mid + 1, Right, Root << 1 | 1);
    PushUp(Root);
}

void IntervalUpdate(int OperateLeft, int OperateRight, int Value, int Left, int Right, int Root) {
    if (OperateLeft <= Left && OperateRight >= Right) {
        Max[Root] += Value;
        Lazy[Root] += Value;
        return;
    }
    int Mid = (Left + Right) >> 1;
    PushDown(Root);
    if (OperateLeft <= Mid) {
        IntervalUpdate(OperateLeft, OperateRight, Value, Left, Mid, Root << 1);
    }
    if (OperateRight > Mid) {
        IntervalUpdate(OperateLeft, OperateRight, Value, Mid + 1, Right, Root << 1 | 1);
    }
    PushUp(Root);
}

long long Query(int OperateLeft, int OperateRight, int Left, int Right, int Root) {
    if (OperateLeft <= Left && OperateRight >= Right) {
        return Max[Root];
    }
    int Mid = (Left + Right) >> 1;
    PushDown(Root);
    long long Ans = -INF;
    if (OperateLeft <= Mid) {
        Ans = max(Ans, Query(OperateLeft, OperateRight, Left, Mid, Root << 1));
    }
    if (OperateRight > Mid) {
        Ans = max(Ans, Query(OperateLeft, OperateRight, Mid + 1, Right, Root << 1 | 1));
    }
    return Ans;
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        Init();
        scanf("%d%d", &N, &M);
        for (int i = 1, X, Y; i < N; ++i) {
            scanf("%d%d", &X, &Y);
            AddEdge(X, Y);
        }
        for (int i = 0; i < N; ++i) {
            scanf("%lld", &Weight[i]);
        }
        Dis[0] = Weight[0];
        Cnt = 0;
        Dfs(0, -1);
        Build(1, N, 1);
        printf("Case #%d:\n", Case);
        for (int Operation = 1, Operate, X, Y; Operation <= M; ++Operation) {
            scanf("%d", &Operate);
            if (Operate == 1) {
                scanf("%d", &X);
                printf("%lld\n", Query(InIndex[X], OutIndex[X], 1, N, 1));
            }
            else {
                scanf("%d%d", &X, &Y);
                IntervalUpdate(InIndex[X], OutIndex[X], Y - Weight[X], 1, N, 1);
                Weight[X] = Y;
            }
        }
    }
    return 0;
}


