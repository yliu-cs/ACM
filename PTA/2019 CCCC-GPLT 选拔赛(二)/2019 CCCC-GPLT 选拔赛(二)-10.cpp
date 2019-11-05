#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2 + 5;

int N, M;
vector<pair<int, int>> G[maxn];
int Dis[maxn];
bool Vis[maxn];
pair<int, int> Ans;

int Dijkstra(int Start) {
    memset(Dis, inf, sizeof(Dis));
    memset(Vis, false, sizeof(Vis));
    Dis[Start] = 0;
    for (int i = 1; i <= N; ++i) {
        int U = -1, Min = inf;
        for (int j = 1; j <= N; ++j) {
            if (!Vis[j] && Dis[j] < Min) {
                U = j;
                Min = Dis[j];
            }
        }
        if (U == -1) return -1;
        Vis[U] = true;
        for (int j = 0; j < G[U].size(); ++j) {
            if (!Vis[G[U][j].first] && Dis[U] + G[U][j].second < Dis[G[U][j].first]) {
                Dis[G[U][j].first] = Dis[U] + G[U][j].second;
            }
        }
    }
    int Res = -1;
    for (int i = 1; i <= N; ++i) {
        if (i == Start) continue;
        Res = max(Res, Dis[i]);
    }
    return Res;
}

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 1, U, V, C; i <= M; ++i) {
        scanf("%d%d%d", &U, &V, &C);
        G[U].push_back(make_pair(V, C));
        G[V].push_back(make_pair(U, C));
    }
    Ans.second = inf;
    for (int i = 1; i <= N; ++i) {
        int Res = Dijkstra(i);
        if (Res == -1) continue;
        if (Res < Ans.second) Ans = make_pair(i, Res);
    }
    if (Ans.second == inf) printf("0\n");
    else printf("%d %d\n", Ans.first, Ans.second);
    return 0;
}

