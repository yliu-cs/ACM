#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
#define min(x,y) x>y?y:x
#define XDebug(x) cout<<#x<<"="<<x<<endl;
#define ArrayDebug(x,i) cout<<#x<<"["<<i<<"]="<<x[i]<<endl;
#define print(x) out(x);putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<ll,ll> PLL;
const int INF = 0x7fffffff;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
template <class T>
inline bool read(T &ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) {
        return false;
    }
    while (c != '-' && (c < '0' || c > '9')) {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return true;
}
template <class T>
inline void out(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        out(x / 10);
    }
    putchar(x % 10 + '0');
}

struct Edge {
    int V, W, Next;
    Edge(int _V = 0, int _W = 0, int _Next = -1): V(_V), W(_W), Next(_Next) {}
};

Edge edges[maxn << 1];
int Head[maxn];
int Tot;
int Depth[maxn];
int T;
int N, E;
int Current[maxn];
queue<int> Que;

void Init() {
    Tot = 0;
    mem(Head, -1);
}

void AddEdge(int U, int V, int W) {
    edges[Tot].V = V;
    edges[Tot].W = W;
    edges[Tot].Next = Head[U];
    Head[U] = Tot++;
}

bool Bfs(int Start, int End) {
    for (int i = 0; i <= N; ++i) {
        Depth[i] = -1;
    }
    while (!Que.empty()) {
        Que.pop();
    }
    Depth[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int Vertex = Que.front(); Que.pop();
        if (Vertex == End) {
            break;
        }
        for (int i = Head[Vertex]; i != -1; i = edges[i].Next) {
            int V = edges[i].V;
            if (Depth[V] == -1 && edges[i].W > 0) {
                Depth[V] = Depth[Vertex] + 1;
                Que.push(V);
            }
        }
    }
    return Depth[End] != -1;
}

int Dfs(int Vertex, int End, int NowFlow) {
    if (Vertex == End || NowFlow == 0) {
        return NowFlow;
    }
    int FindFlow = 0, Flow;
    for (int &i = Current[Vertex]; i != -1; i = edges[i].Next) {
        int V = edges[i].V;
        if (edges[i].W > 0 && Depth[V] == Depth[Vertex] + 1) {
            Flow = Dfs(V, End, min(NowFlow - FindFlow, edges[i].W));
            if (Flow > 0) {
                edges[i].W -= Flow;
                edges[i ^ 1].W += Flow;
                FindFlow += Flow;
                if (FindFlow == NowFlow) {
                    return NowFlow;
                }
            }
        }
    }
    if (!FindFlow) {
        Depth[Vertex] = -2;
    }
    return FindFlow;
}

int Dinic(int Start, int End) {
    int MaxFlow = 0;
    while (Bfs(Start, End)) {
        for (int i = 1; i <= N; ++i) {
            Current[i] = Head[i];
        }
        MaxFlow += Dfs(Start, End, INF);
    }
    return MaxFlow;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        Init();
        int Start = INF, End = -INF;
        int StartIndex = 1, EndIndex = 1;
        scanf("%d%d", &N, &E);
        for (int i = 1, X, Y; i <= N; ++i) {
            scanf("%d%d", &X, &Y);
            if (X < Start) {
                Start = X;
                StartIndex = i;
            }
            if (X > End) {
                End = X;
                EndIndex = i;
            }
        }
        for (int i = 1, U, V, W; i <= E; ++i) {
            scanf("%d%d%d", &U, &V, &W);
            AddEdge(U, V, W);
            AddEdge(V, U, W);
        }
        printf("%d\n", Dinic(StartIndex, EndIndex));
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

