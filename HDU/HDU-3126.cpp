#include <bits/stdc++.h>
using namespace std;
typedef double db;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
const db eps = 1e-9;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
int Cmp(db Key1, db Key2) {return Sgn(Key1 - Key2);}
struct Point {db X, Y;};
typedef Point Vector;
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};}
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};}
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;}
db operator ^ (Vector Key1, Vector Key2) {return Key1.X * Key2.Y - Key1.Y * Key2.X;}
db GetLen(Vector Key) {return sqrt(Key * Key);};
db DisPointToPoint(Point Key1, Point Key2) {return GetLen(Key2 - Key1);}
struct Line {Point S, T;};
typedef Line Segment;
db GetLen(Segment Key) {return GetLen(Key.T - Key.S);}
db DisPointToLine(Point Key1, Line Key2) {return fabs((Key1 - Key2.S) ^ (Key2.T - Key2.S)) / GetLen(Key2);}
db DisPointToSeg(Point Key1, Segment Key2) {
    if (Sgn((Key1 - Key2.S) * (Key2.T - Key2.S)) < 0 || Sgn((Key1 - Key2.T) * (Key2.S - Key2.T)) < 0) {
        return min(DisPointToPoint(Key1, Key2.S), DisPointToPoint(Key1, Key2.T));
    }
    return DisPointToLine(Key1, Key2);
}
struct Circle {Point Center; db Radius;};
bool IsCircleInterSeg(Circle Key1, Segment Key2) {return Cmp(DisPointToSeg(Key1.Center, Key2), Key1.Radius) <= 0;}
struct Lich {Circle Pos; int T;};

struct Edge {int V, Weight, Next;};
Edge edges[100005];
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

int T;
int N, M, K;
Lich lichs[maxn];
Point wisps[maxn];
Circle trees[maxn];
vector<int> Link[maxn];
int Max;
int Left, Right;
int Ans;

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d%d%d", &N, &M, &K);
        for (int i = 1; i <= N; ++i) scanf("%lf%lf%lf%d", &lichs[i].Pos.Center.X, &lichs[i].Pos.Center.Y, &lichs[i].Pos.Radius, &lichs[i].T);
        for (int i = 1; i <= M; ++i) scanf("%lf%lf", &wisps[i].X, &wisps[i].Y);
        for (int i = 1; i <= K; ++i) scanf("%lf%lf%lf", &trees[i].Center.X, &trees[i].Center.Y, &trees[i].Radius);
        Max = -1;
        for (int i = 1; i <= N; ++i) {
            Max = max(Max, lichs[i].T); Link[i].clear();
            for (int j = 1; j <= M; ++j) {
                if (Cmp(DisPointToPoint(lichs[i].Pos.Center, wisps[j]), lichs[i].Pos.Radius) <= 0) {
                    bool Flag = true;
                    for (int k = 1; k <= K; ++k)
                        if (IsCircleInterSeg(trees[k], (Segment){lichs[i].Pos.Center, wisps[j]})) Flag = false;
                    if (Flag) Link[i].push_back(j);
                }
            }
        }
        Ans = -1; Left = 0; Right = INF;
        while (Left <= Right) {
            int Mid = (Left + Right) >> 1;
            GraphInit();
            for (int i = 1; i <= N; ++i) {
                AddEdge(0, i, Mid / lichs[i].T + 1);
                for (int j = 0; j < (int)Link[i].size(); ++j) AddEdge(i, N + Link[i][j], 1);
            }
            for (int i = 1; i <= M; ++i) AddEdge(N + i, N + M + 1, 1);
            if (Dinic(0, N + M + 1) >= M) {
                Ans = Mid;
                Right = Mid - 1;
            }
            else Left = Mid + 1;
        }
        printf("%d\n", Ans);
    }
    return 0;
}

