#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <set>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 110;
const double eps = 1e-5;

struct connecet {
    int v;
    int cost;
};

int max_level_gap, n;
int res;
int start;
int basic_level;
int max_buy_level;
int every_cost[maxn];
int every_level[maxn];
int cost[maxn];
bool vis[maxn];
vector<connecet> Adj[maxn];

void init() {
    res = INF;
    mem(every_cost, 0);
    mem(every_level, 0);
    mem(cost, INF);
    mem(vis, 0);
    return;
}

void Get_information() {
    cin >> max_level_gap >> n;
    for (int i = 1; i <= n; ++i) {
        int p, l, x;
        cin >> p >> l >> x;
        every_cost[i] = p;
        every_level[i] = l;
        if (i == 1) {
            basic_level = l;
        }
        while (x--) {
            int t, v;
            cin >> t >> v;
			connecet add;
			add.v = i;
			add.cost = v;
			Adj[t].push_back(add);
        }
    }
    return;
}

void Dijkstra() {
    max_buy_level = every_level[start];
    for (int i = 1; i <= n; ++i) {
        cost[i] = every_cost[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (max_buy_level > every_level[i] || abs(every_level[i] - max_buy_level) > max_level_gap) {
            vis[i] = 1;
        }
        else {
            vis[i] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int u = -1, min = INF;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && cost[j] < min) {
                u = j;
                min = cost[j];
            }
        }
        vis[u] = 1;
        for (int j = 0; j < Adj[u].size(); ++j) {
            int v = Adj[u][j].v;
            if (!vis[v] && cost[u] + Adj[u][j].cost < cost[v]) {
                cost[v] = cost[u] + Adj[u][j].cost;
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    Get_information();
    for (int i = 1; i <= n; ++i) {
        start = i;
        Dijkstra();
        if (cost[1] < res) {
            res = cost[1];
        }
    }
    cout << res;
    return 0;
}
