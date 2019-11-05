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
const int maxn = 4e2 + 5;
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

int N, F, D;
int Depth[maxn];
int Adj[maxn][maxn];

// Dinic板子
bool Bfs(int Start, int End) {
    std::queue<int> Que;
    memset(Depth, -1, sizeof(Depth));
    Depth[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int Vertex = Que.front();
        Que.pop();
        for (int i = 0; i <= F + N + N + D + 1; ++i) {
            if (Depth[i] == -1 && Adj[Vertex][i]) {
                Depth[i] = Depth[Vertex] + 1;
                Que.push(i);
            }
        }
    }
    return Depth[End] > 0;
}

int Dfs(int Vertex, int End, int NowFlow) {
    if (Vertex == End) {
        return NowFlow;
    }
    int FindFlow = 0;
    for (int i = 0; i <= F + N + N + D + 1; ++i) {
        if (Adj[Vertex][i] && Depth[i] == Depth[Vertex] + 1) {
            FindFlow = Dfs(i, End, std::min(NowFlow, Adj[Vertex][i]));
            if (FindFlow) {
                Adj[Vertex][i] -= FindFlow;
                Adj[i][Vertex] += FindFlow;
                return FindFlow;
            }
        }
    }
    if (!FindFlow) {
        Depth[Vertex] = -2;
    }
    return false;
}

int Dinic(int Start, int End) {
    int MaxFlow = 0;
    while (Bfs(Start, End)) {
        MaxFlow += Dfs(Start, End, INF);
    }
    return MaxFlow;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (read(N) && read(F) && read(D)) {
        mem(Adj, 0);
        // 建图
        // 源点与食物建边
        for (int i = 1; i <= F; ++i) {
            Adj[0][i] = 1;
        }
        // 饮料与汇点建边
        for (int i = 1; i <= D; ++i) {
            Adj[F + N + N + i][F + N + N + D + 1] = 1;
        }
        // 牛1与牛2建边
        for (int i = F + 1; i <= F + N; ++i) {
            Adj[i][i + N] = 1;
        }
        for (int i = 1, Fn, Dn; i <= N; ++i) {
            read(Fn); read(Dn);
            // 食物与牛1建边
            for (int j = 1, FNum; j <= Fn; ++j) {
                read(FNum);
                Adj[FNum][F + i] = 1;
            }
            // 牛2与饮料建边
            for (int j = 1, Dnum; j <= Dn; ++j) {
                read(Dnum);
                Adj[F + N + i][F + N + N + Dnum] = 1;
            }
        }
        // 输出源点到汇点的最大流
        print(Dinic(0, F + N + N + D + 1));
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

