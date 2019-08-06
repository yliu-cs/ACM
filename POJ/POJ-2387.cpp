#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 400000;

struct connect {
    int v;
    int time;
};

int dis[maxn],N,M;
bool vis[maxn];
vector<connect> Adj[maxn];

void Dijkstra(int s) {
    mem(dis, INF);
    mem(vis, 0);
    dis[s] = 0;
    for (int i = 0;i < M;++i) {
        int u = -1,min = INF;
        for (int j = 1;j <= M;++j) {
            if (vis[j] == 0 && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = 1;
        for (int j = 0;j < Adj[u].size();++j) {
            int v = Adj[u][j].v;
            if (vis[v] == 0 && dis[u] + Adj[u][j].time < dis[v]) {
                dis[v] = dis[u] + Adj[u][j].time;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int t = N;
    while (t--) {
        int A,B,C;
        cin >> A >> B >> C;
        bool flag = 0;
        for (int i = 0;i < Adj[A].size();++i) {
            if (B == Adj[A][i].v) {
                if (C >= Adj[A][i].time) {
                    flag = 1;
                }
                else {
                    Adj[A][i].time = C;
                    flag = 1;
                }
            }
        }
        if (flag) {
            for (int i = 0;i < Adj[B].size();++i) {
                if (A == Adj[B][i].v) {
                    if (C < Adj[B][i].time) {
                        Adj[B][i].time = C;
                    }
                }
            }
        }
        if (flag) {
            continue;
        }
        else {
            connect add;
            add.v = B;
            add.time = C;
            Adj[A].push_back(add);
            add.v = A;
            add.time = C;
            Adj[B].push_back(add);
        }
    }
    Dijkstra(M);
    cout << dis[1] << endl;
    for (int i = 1;i <= M;++i) {
        Adj[i].clear();
    }
    return 0;
}
