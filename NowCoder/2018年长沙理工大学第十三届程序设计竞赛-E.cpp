#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;
 
struct connect {
    int v, dis;
    bool operator < (const connect &a) const {
        return a.dis < dis;
    }
};
 
int n, m;
int dis[maxn];
bool vis[maxn];
vector<connect> Adj[maxn];
 
void Dijkstra() {
    mem(dis, INF);
    mem(vis, 0);
    dis[1] = 0;
    priority_queue<connect> que;
    connect temp_push;
    temp_push.v = 1;
    temp_push.dis = 0;
    que.push(temp_push);
    while (!que.empty()) {
        connect keep = que.top();
        que.pop();
        int v = keep.v;
        if (dis[v] < keep.dis || vis[v]) {
            continue;
        }
        if (v == n) {
            return;
        }
        vis[v] = 1;
        for (int i = 0; i < Adj[v].size(); ++i) {
            connect e = Adj[v][i];
            if (!vis[e.v] && dis[e.v] > dis[v] + e.dis) {
                dis[e.v] = dis[v] + e.dis;
                connect keep_add;
                keep_add.v = e.v;
                keep_add.dis = dis[e.v];
                que.push(keep_add);
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v, input_dis;
        cin >> u >> v >> input_dis;
        connect add;
        add.v = v;
        add.dis = input_dis;
        Adj[u].push_back(add);
        add.v = u;
        Adj[v].push_back(add);
    }
    Dijkstra();
    if (dis[n] == INF) {
        cout << "qwb baka";
    }
    else {
        cout << dis[n];
    }
    return 0;
}
