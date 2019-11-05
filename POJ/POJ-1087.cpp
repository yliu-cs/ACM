#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
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
const int maxn = 8e2 + 5;
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

int N, M, K;
int AddPlugCnt;
int Depth[maxn];
int Adj[maxn][maxn];
map<string, int> m;

bool Bfs(int Start, int End) {
    std::queue<int> Que;
    memset(Depth, -1, sizeof(Depth));
    Depth[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int Vertex = Que.front();
        Que.pop();
        for (int i = 0; i <= N + M + AddPlugCnt + 1; ++i) {
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
    for (int i = 0; i <= N + M + AddPlugCnt + 1; ++i) {
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
    mem(Adj, 0);
    read(N);
    vector<string> Plug(N + 1);
    // 插头
    for (int i = 1; i <= N; ++i) {
        cin >> Plug[i];
        m[Plug[i]] = i;
    }
    read(M);
    AddPlugCnt = 0;
    // 设备与插头相连
    for (int i = 1; i <= M; ++i) {
        string device, plug;
        cin >> device >> plug;
        m[device] = N + i;
        if (!m[plug]) {
            m[plug] = N + M + (++AddPlugCnt);
        }
        Adj[m[device]][m[plug]] = 1;
        Adj[0][m[device]] = 1;
    }
    read(K);
    // 插头相连
    for (int i = 1; i <= K; ++i) {
        string plug1, plug2;
        cin >> plug1 >> plug2;
        Adj[m[plug1]][m[plug2]] = 1;
    }
    // 插头与汇点相连
    for (int i = 1; i <= N; ++i) {
        Adj[m[Plug[i]]][N + M + AddPlugCnt + 1] = INF;
    }
    print(M - Dinic(0, N + M + AddPlugCnt + 1));
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

