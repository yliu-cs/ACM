#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
#define XDebug(x) cout<<#x<<"="<<x<<endl;
#define ArrayDebug(x,i) cout<<#x<<"["<<i<<"]="<<x[i]<<endl;
#define print(x) out(x);putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<ll,ll> PLL;
const int INF = 0x3f3f3f3f;
const int maxn = 1e2 + 5;
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

struct Link {
    int V, Weight, Next;
    Link(int _V = 0, int _Weight = 0, int _Next = 0): V(_V), Weight(_Weight), Next(_Next) {}
};

Link edges[1000005];
int Head[maxn << 1];
int Tot;
int Depth[maxn << 1];
int Current[maxn << 1];
int N, NP, NC, M;

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V, int Weight, int ReverseWeight = 0) {
    edges[Tot].V = V;
    edges[Tot].Weight = Weight;
    edges[Tot].Next = Head[U];
    Head[U] = Tot++;
    edges[Tot].V = U;
    edges[Tot].Weight = ReverseWeight;
    edges[Tot].Next = Head[V];
    Head[V] = Tot++;
}

bool Bfs(int Start, int End) {
    memset(Depth, -1, sizeof(Depth));
    std::queue<int> Que;
    Depth[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int Vertex = Que.front();
        Que.pop();
        for (int i = Head[Vertex]; i != -1; i = edges[i].Next) {
            if (Depth[edges[i].V] == -1 && edges[i].Weight > 0) {
                Depth[edges[i].V] = Depth[Vertex] + 1;
                Que.push(edges[i].V);
            }
        }
    }
    return Depth[End] != -1;
}

int Dfs(int Vertex, int End, int NowFlow) {
    if (Vertex == End || NowFlow == 0) {
        return NowFlow;
    }
    int UsableFlow = 0, FindFlow;
    for (int &i = Current[Vertex]; i != -1; i = edges[i].Next) {
        if (edges[i].Weight > 0 && Depth[edges[i].V] == Depth[Vertex] + 1) {
            FindFlow = Dfs(edges[i].V, End, std::min(NowFlow - UsableFlow, edges[i].Weight));
            if (FindFlow > 0) {
                edges[i].Weight -= FindFlow;
                edges[i ^ 1].Weight += FindFlow;
                UsableFlow += FindFlow;
                if (UsableFlow == NowFlow) {
                    return NowFlow;
                }
            }
        }
    }
    if (!UsableFlow) {
        Depth[Vertex] = -2;
    }
    return UsableFlow;
}

int Dinic(int Start, int End) {
    int MaxFlow = 0;
    while (Bfs(Start, End)) {
        for (int i = 0; i <= N + 1; ++i) {
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
    while (cin >> N >> NP >> NC >> M) {
        Init();
        for (int i = 1, U, V, C; i <= M; ++i) {
            char Waste;
            cin >> Waste >> U >> Waste >> V >> Waste >> C;
            U++; V++;
            AddEdge(U, V, C);
        }
        for (int i = 1, X, C; i <= NP; ++i) {
            char Waste;
            cin >> Waste >> X >> Waste >> C;
            X++;
            AddEdge(0, X, C);
        }
        for (int i = 1, X, C; i <= NC; ++i) {
            char Waste;
            cin >> Waste >> X >> Waste >> C;
            X++;
            AddEdge(X, N + 1, C);
        }
        cout << Dinic(0, N + 1) << endl;
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

