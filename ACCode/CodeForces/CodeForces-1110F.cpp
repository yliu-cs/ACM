#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int maxn = 5e5 + 5;

//------Graph------
struct Edge {int V, Weight;};
vector<Edge> edges[maxn];

//------Segment Tree----
ll Val[maxn];

struct SegmentTree {
    ll Dis[maxn << 2];
    ll Lazy[maxn << 2];

    void PushUp(int Root) {
        Dis[Root] = min(Dis[Root << 1], Dis[Root << 1 | 1]);
    }

    void PushDown(int Root) {
        if (!Lazy[Root]) return;
        Lazy[Root << 1] += Lazy[Root];
        Lazy[Root << 1 | 1] += Lazy[Root];
        Dis[Root << 1] += Lazy[Root];
        Dis[Root << 1 | 1] += Lazy[Root];
        Lazy[Root] = 0;
    }

    void Build(int Left, int Right, int Root) {
        if (Left == Right) {
            Dis[Root] = Val[Left];
            return;
        }
        int Mid = (Left + Right) >> 1;
        Build(Left, Mid, Root << 1);
        Build(Mid + 1, Right, Root << 1 | 1);
        PushUp(Root);
    }

    void Update(int OperateLeft, int OperateRight, int Value,
                int Left, int Right, int Root) {
        if (OperateLeft <= Left && OperateRight >= Right) {
            Lazy[Root] += Value;
            Dis[Root] += Value;
            return;
        }
        PushDown(Root);
        int Mid = (Left + Right) >> 1;
        if (OperateLeft <= Mid) Update(OperateLeft, OperateRight, Value, Left, Mid, Root << 1);
        if (OperateRight > Mid) Update(OperateLeft, OperateRight, Value, Mid + 1, Right, Root << 1 | 1);
        PushUp(Root);
    }

    ll Query(int OperateLeft, int OperateRight, int Left, int Right, int Root) {
        if (OperateLeft <= Left && OperateRight >= Right) return Dis[Root];
        PushDown(Root);
        int Mid = (Left + Right) >> 1;
        ll Ans = INF;
        if (OperateLeft <= Mid) Ans = min(Ans, Query(OperateLeft, OperateRight, Left, Mid, Root << 1));
        if (OperateRight > Mid) Ans = min(Ans, Query(OperateLeft, OperateRight, Mid + 1, Right, Root << 1 | 1));
        return Ans;
    }
};

SegmentTree SGT;

//------Dfs Order------
int DfsClock;
int In[maxn];
int Out[maxn];

void DfsOrder(int Cur, ll Dis) {
    In[Cur] = ++DfsClock;
    for (auto it : edges[Cur]) DfsOrder(it.V, Dis + it.Weight);
    if (edges[Cur].empty()) Val[Cur] = Dis;
    else Val[Cur] = INF;
    Out[Cur] = DfsClock;
}

//------Query------
struct Query {int Left, Right, Id;};
vector<Query> querys[maxn];

int N, Q;
ll Ans[maxn];

void Dfs(int Cur, ll Dis) {
    for (auto it : querys[Cur]) Ans[it.Id] = SGT.Query(it.Left, it.Right, 1, N, 1) + Dis;
    for (auto it : edges[Cur]) {
        SGT.Update(In[it.V], Out[it.V], -it.Weight * 2, 1, N, 1);
        Dfs(it.V, it.Weight + Dis);
        SGT.Update(In[it.V], Out[it.V], it.Weight * 2, 1, N, 1);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &Q);
    for (int i = 2, U, W; i <= N; ++i) {
        scanf("%d%d", &U, &W);
        edges[U].push_back((Edge){i, W});
    }
    DfsOrder(1, 0);
    SGT.Build(1, N, 1);
    for (int i = 1, V, L, R; i <= Q; ++i) {
        scanf("%d%d%d", &V, &L, &R);
        querys[V].push_back((Query){L, R, i});
    }
    Dfs(1, 0);
    for (int i = 1; i <= Q; ++i) printf("%lld\n", Ans[i]);
    return 0;
}

