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
#include <cstdlib>
#include <sstream>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;     // 正无穷（可以用memset）
const int maxn = 1e5+5;

struct connect {
    int v;              // 连接的顶点
    int time;            // 权值
};

int dis[maxn],N,M;              // N为顶点个数,M是输入连接组数,dis数组存最短路径
bool vis[maxn];                 // vis数组保存每个顶点的访问情况
vector<connect> Adj[maxn];      // Adj结构体数组存连接情况和权值

// Dijkstra算法求图中一点到另外所有点最小权值
void Dijkstra() {
    mem(dis, INF);              // 将dis数组初始化为正无穷
    mem(vis, 0);                // 将vis标记数组初始化为0
    dis[1] = 0;                 // 将起点到起点的最短路径设为0,这里1为起点
    for (int i = 0;i < N;++i) { // 循环n次求出起点到每个点的最短路径
        int u = -1,min = INF;   // u记录顶点,min记录最短路径
        for (int j = 1;j <= N;++j) { // 寻找dis数组中的最小值
            if (vis[j] == 0 && dis[j] < min) {  // 筛选没有被标记过并且起点到未被标记顶点最短路径
                u = j;          // 记录下筛选出的顶点
                min = dis[j];   // 记录起点到未被标记顶点的最短路径
            }
        }
        if (u == -1) {          // 如果没有找到符合要求的顶点则返回
            return;
        }
        vis[u] = 1;             // 将找出的顶点标记
        for (int j = 0;j < Adj[u].size();++j) {     // 循环更新顶点加入后起点到其它各个未标记顶点的最短路径
            int v = Adj[u][j].v;                    // 记录顶点为v
            if (vis[v] == 0 && dis[u] + Adj[u][j].time < dis[v]) {   // 顶点没有被标记过&起点到v顶点路径小于已记录路径
                dis[v] = dis[u] + Adj[u][j].time;        // 更新起始点到v顶点的最短路径
            }
        }
    }
}

int main() {
    // 加速输入输出
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 输入顶点数和连接信息组数
    while (cin >> N >> M,N,M) {
        while (M--) {
            int A,B,C;
            cin >> A >> B >> C;
            connect add;
            add.v = B;
            add.time = C;
            Adj[A].push_back(add);
            // 无向图反向添加一次
            add.v = A;
            Adj[B].push_back(add);
        }
        Dijkstra();
        cout << dis[N] << endl;
        for (int i = 1;i <= N;++i) {
            Adj[i].clear();
        }
    }
    return 0;
}
