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
#include<functional>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 510;
const double eps = 1e-5;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;

struct connect {
    int v;
    int dis;
};

int n, m;
int dis[maxn];
vector<connect> Adj[maxn];

// 堆优化迪杰斯特拉求最短路
void Dijkstra() {
    priority_queue<P, vector<P>, greater<P> > que;
    mem(dis, INF);
    dis[1] = 0;
    que.push(P(0, 1));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        if (p.second == n) {
            break;
        }
		// 松弛操作
        for (int i = 0; i < Adj[v].size(); ++i) {
            connect e = Adj[v][i];
            if (dis[e.v] > dis[v] + e.dis) {
                dis[e.v] = dis[v] + e.dis;
                que.push(P(dis[e.v], e.v));
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m, n, m) {
		// 数据读取，无向图反向添加边
        while (m--) {
            int Input_u, Input_v, Input_dis;
            cin >> Input_u >> Input_v >> Input_dis;
            connect add;
            add.v = Input_v;
            add.dis = Input_dis;
            Adj[Input_u].push_back(add);
            add.v = Input_u;
            Adj[Input_v].push_back(add);
        }
        Dijkstra();
        cout << dis[n] << endl;
		// 清空邻接表
        for (int i = 1; i <= n; ++i) {
            Adj[i].clear();
        }
    }
    return 0;
}
