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

int dis[maxn],N;
bool vis[maxn];
vector<connect> Adj[maxn];

void Dijkstra(int s) {
    mem(dis, INF);
    mem(vis, 0);
    dis[s] = 0;
    for (int i = 0;i < N;++i) {
        int u = -1,min = INF;
        for (int j = 1;j <= N;++j) {
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
    cin >> N;
    for (int k = 2;k <= N;++k) {
        for (int i = 1;i < k;++i) {
            string a;
            cin >> a;
            if (a[0] != 'x') {
                int b = 0;
                int len = a.length();
                for (int j = 0;j < len;++j) {
                    b = b * 10 + (a[j] - '0');
                }
                connect add;
                add.v = i;
                add.time = b;
                Adj[k].push_back(add);
                add.v = k;
                Adj[i].push_back(add);
            }
        }
    }
    Dijkstra(1);
    int res = -INF;
    for (int i = 1;i <= N;++i) {
        if (res < dis[i]) {
            res = dis[i];
        }
    }
    cout << res << endl;
    for (int i = 1;i <= N;++i) {
        Adj[i].clear();
    }
    return 0;
}
