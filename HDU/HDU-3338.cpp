#include <bits/stdc++.h>
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

Link edges[2500005];
int Head[maxn * maxn * 2];
int Tot;
int Depth[maxn * maxn * 2];
int Current[maxn * maxn * 2];

int N, M;
int RCnt, CCnt;
char Ans[maxn][maxn];
int Info[maxn][maxn];
int Book[maxn][maxn];
PII Symbol[maxn][maxn];
PII Record[maxn][maxn];

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V, int Weight, int ReverseWeight = 0, int X = 0, int Y = 0) {
    edges[Tot].V = V;
    edges[Tot].Weight = Weight;
    edges[Tot].Next = Head[U];
    Head[U] = Tot++;
    if (X && Y) {
        Book[X][Y] = Tot;
    }
    edges[Tot].V = U;
    edges[Tot].Weight = ReverseWeight;
    edges[Tot].Next = Head[V];
    Head[V] = Tot++;
}

bool Bfs(int Start, int End) {
    memset(Depth, -1, sizeof(Depth));
    queue<int> Que;
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
            FindFlow = Dfs(edges[i].V, End, min(NowFlow - UsableFlow, edges[i].Weight));
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
        for (int i = 0; i <= RCnt + N * M + CCnt + 1; ++i) {
            Current[i] = Head[i];
        }
        MaxFlow += Dfs(Start, End, INF);
    }
    return MaxFlow;
}

void Build() {
    char Ch[10];
    RCnt = 0, CCnt = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            Symbol[i][j].first = 0; Symbol[i][j].second = 0;
            Record[i][j].first = 0; Record[i][j].second = 0;
            scanf("%s", Ch);
            if (Ch[3] == 'X') {
                continue;
            }
            else if (Ch[0] == '.') {
                Ans[i][j] = '0';
                Record[i][j].first = Record[i][j - 1].first;
                Record[i][j].second = Record[i - 1][j].second;
                Info[i][Record[i][j].first] -= 1;
                Info[Record[i][j].second][j] -= 1000;
            }
            else {
                if (Ch[0] != 'X') {
                    int Temp = (Ch[0] - '0') * 100 + (Ch[1] - '0') * 10 + (Ch[2] - '0');
                    Info[i][j] = Temp * 1000;
                    Symbol[i][j].first = (++CCnt);
                }
                if (Ch[4] != 'X') {
                    int Temp = (Ch[4] - '0') * 100 + (Ch[5] - '0') * 10 + (Ch[6] - '0');
                    Info[i][j] = Info[i][j] == -1 ? Temp : Info[i][j] + Temp;
                    Symbol[i][j].second = (++RCnt);
                }
                Record[i][j].first = j; Record[i][j].second = i;
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (Info[i][j] % 1000) {
                AddEdge(0, Symbol[i][j].second, Info[i][j] % 1000);
            }
            if (Info[i][j] / 1000) {
                AddEdge(RCnt + N * M + Symbol[i][j].first, RCnt + N * M + CCnt + 1, Info[i][j] / 1000);
            }
            if (Ans[i][j] == '0') {
                AddEdge(Symbol[i][Record[i][j].first].second, RCnt + M * (i - 1) + j, 8);
                AddEdge(RCnt + M * (i - 1) + j, RCnt + N * M + Symbol[Record[i][j].second][j].first, 8, 0, i, j);
            }
        }
    }
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d", &N, &M)) {
        Init();
        mem(Info, 0);
        mem(Book, -1);
        mem(Ans, '_');
        Build();
        Dinic(0, RCnt + N * M + CCnt + 1);
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (Book[i][j] != -1) {
                    Ans[i][j] = '0' + edges[Book[i][j]].Weight + 1;
                }
                else if (Ans[i][j] == '0') {
                    Ans[i][j]++;
                }
                printf("%c", Ans[i][j]);
                if (j != M) {
                    putchar(' ');
                }
            }
            putchar('\n');
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

