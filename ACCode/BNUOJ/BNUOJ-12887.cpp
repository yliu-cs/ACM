#include <bits/stdc++.h>
using namespace std;
typedef double db;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 5;
const db eps = 1e-9;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
int Cmp(db Key1, db Key2) {return Sgn(Key1 - Key2);}
struct Point {db X, Y;};
typedef Point Vector;
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};}
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};}
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;}
db operator ^ (Vector Key1, Vector Key2) {return Key1.X * Key2.Y - Key1.Y * Key2.X;}
db GetLen(Vector Key) {return sqrt(Key * Key);}
db DisPointToPoint(Point Key1, Point Key2) {return GetLen(Key2 - Key1);}
struct Line {Point S, T;};
typedef Line Segment;
struct Circle {Point Center; db Radius;};
bool IsCircleInterCircle(Circle Key1, Circle Key2) {return Cmp(DisPointToPoint(Key1.Center, Key2.Center), Key1.Radius + Key2.Radius) <= 0;}

struct Edge {int V, Weight, Next;};

Edge edges[maxn << 4];
int Head[maxn];
int Tot;
int Depth[maxn];
int Current[maxn];

void GraphInit() {Tot = 0; memset(Head, -1, sizeof(Head));}
void AddEdge(int U, int V, int Weight, int ReverseWeight = 0) {
    edges[Tot] = (Edge){V, Weight, Head[U]};
    Head[U] = Tot++;
    edges[Tot] = (Edge){U, ReverseWeight, Head[V]};
    Head[V] = Tot++;
}

bool Bfs(int Start, int End) {
    memset(Depth, -1, sizeof(Depth));
    std::queue<int> Que;
    Depth[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int Cur = Que.front();
        Que.pop();
        for (int i = Head[Cur]; ~i; i = edges[i].Next) {
            if (Depth[edges[i].V] == -1 && edges[i].Weight > 0) {
                Depth[edges[i].V] = Depth[Cur] + 1;
                Que.push(edges[i].V);
            }
        }
    }
    return Depth[End] != -1;
}

int Dfs(int Cur, int End, int NowFlow) {
    if (Cur == End || NowFlow == 0) return NowFlow;
    int UsableFlow = 0, FindFlow;
    for (int &i = Current[Cur]; ~i; i = edges[i].Next) {
        if (edges[i].Weight > 0 && Depth[edges[i].V] == Depth[Cur] + 1) {
            FindFlow = Dfs(edges[i].V, End, std::min(NowFlow - UsableFlow, edges[i].Weight));
            if (FindFlow > 0) {
                edges[i].Weight -= FindFlow;
                edges[i ^ 1].Weight += FindFlow;
                UsableFlow += FindFlow;
                if (UsableFlow == NowFlow) return NowFlow;
            }
        }
    }
    if (!UsableFlow) Depth[Cur] = -2;
    return UsableFlow;
}

int Dinic(int Start, int End) {
    int MaxFlow = 0;
    while (Bfs(Start, End)) {
        for (int i = Start; i <= End; ++i) Current[i] = Head[i];
        MaxFlow += Dfs(Start, End, INF);
    }
    return MaxFlow;
}

bool CheckCircle(Circle Key1, db Key2) {
    return Cmp(Key1.Center.Y - Key1.Radius, Key2) <= 0 && Cmp(Key1.Center.Y + Key1.Radius, Key2) >= 0;
}

db L, W;
int N;
Circle Daniel[maxn];

int main(int argc, char *argv[]) {
    scanf("%lf%lf%d", &L, &W, &N);
    for (int i = 1; i <= N; ++i) scanf("%lf%lf%lf", &Daniel[i].Center.X, &Daniel[i].Center.Y, &Daniel[i].Radius);
    GraphInit();
    for (int i = 1; i <= N; ++i) AddEdge(i, N + i, 1);
    for (int i = 1; i <= N; ++i) {
        if (CheckCircle(Daniel[i], 0)) AddEdge(0, i, INF);
        if (CheckCircle(Daniel[i], W)) AddEdge(N + i, 2 * N + 1, INF);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (IsCircleInterCircle(Daniel[i], Daniel[j])) {
                AddEdge(N + i, j, INF);
                AddEdge(N + j, i, INF);
            }
        }
    }
    printf("%d\n", Dinic(0, 2 * N + 1));
    return 0;
}

