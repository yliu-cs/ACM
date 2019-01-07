#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
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
const int maxn = 5e1 + 5;
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

int P, N;
int Ans;
int Q[maxn];
int Depth[maxn];
int Basic[maxn][maxn];
int Adj[maxn][maxn];
vector<int> S[maxn], D[maxn];
vector<pair<int, pair<int, int> > > Res;

bool Bfs(int Start, int End) {
    std::queue<int> Que;
    memset(Depth, -1, sizeof(Depth));
    Depth[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int Vertex = Que.front();
        Que.pop();
        for (int i = 0; i <= N + 1; ++i) {
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
    for (int i = 0; i <= N + 1; ++i) {
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
    read(P); read(N);
    mem(Adj, 0);
    mem(Basic, 0);
    for (int i = 1, flag; i <= N; ++i) {
        read(Q[i]);
        S[i].clear(); D[i].clear();
        flag = 1;
        for (int j = 1, X; j <= P; ++j) {
            read(X);
            S[i].pb(X);
            if (X == 1) {
                flag = 0;
            }
        }
        if (flag) {
            Adj[0][i] = Q[i];
            Basic[0][i] = Q[i];
        }
        flag = 1;
        for (int j = 1, X; j <= P; ++j) {
            read(X);
            D[i].pb(X);
            if (!X) {
                flag = 0;
            }
        }
        if (flag) {
            Adj[i][N + 1] = Q[i];
            Basic[i][N + 1] = Q[i];
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i != j) {
                bool flag = 1;
                for (int k = 0; k < P; ++k) {
                    if (D[i][k] == S[j][k] || S[j][k] == 2) {
                        continue;
                    }
                    else {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    Adj[i][j] = min(Q[i], Q[j]);
                    Basic[i][j] = min(Q[i], Q[j]);
                }
            }
        }
    }
    Ans = Dinic(0, N + 1);
    Res.clear();
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (Basic[i][j] > Adj[i][j]) {
                Res.pb(mp(Basic[i][j] - Adj[i][j], mp(i, j)));
            }
        }
    }
    printf("%d %d\n", Ans, int(Res.size()));
    for (int i = 0; i < int(Res.size()); ++i) {
        printf("%d %d %d\n", Res[i].second.first, Res[i].second.second, Res[i].first);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

