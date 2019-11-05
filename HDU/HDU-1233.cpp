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
const int maxn = 110;

struct connect {
    int v;      // 连接顶点
    int dis;    // 权值
};

vector<connect> Adj[maxn];      // Adj数组存连接情况
int n,E,dis[maxn];              // dis存每个顶点到已生成树的权值
bool vis[maxn] = {0};           // vis保存每个顶点的访问情况
int res = 0;                    // 结果（最小生成树的权值之和）

// Prim算法求最小生成树，这里1为起始点
int Prim() {
    mem(dis, INF);              // 将所有顶点的权值初始化为正无穷
    mem(vis, 0);                // 将所有顶点的访问情况设为未标记
    dis[1] = 0;                 // 将起点的权值设置为0
    res = 0;                    // 最小生成树结果初始化为0
    for (int i = 1;i <= n;++i) { // 遍历所有顶点，保证结果没有未被访问的顶点
        int u = -1,min = INF;   // 用min筛选出dis中的最小值（即未被筛选过的顶点到已生成树的权值的最小值），用u记录此顶点
        for (int j = 1;j <= n;++j) {     // 筛选过程
            if (vis[j] == 0 && dis[j] < min) {  // 判断条件为1.未被筛选过，2.小
                u = j;              // 记录顶点
                min = dis[j];       // 记录最小权值
            }
        }
        vis[u] = 1;     // 将筛选出的此点标记
        res += min;     // 将此点到已生成树的最小权值加入到结果中
        // 已生成树已更新
        for (int j = 0;j < Adj[u].size();++j) {     //更新未被筛选过的顶点到新已生成树的权值
            int v = Adj[u][j].v;        // v变量记录顶点
            if (vis[v] == 0 && Adj[u][j].dis < dis[v]) {    // 判断条件为1.此定点未被筛选过，2.此顶点到新已生成树的距离可以更新之前此顶点到已生成树的距离
                dis[v] = Adj[u][j].dis;     // 更新此顶点到已生成树的距离
            }
        }
    }
    return res;     // 返回结果
}

int main() {
    // 加速输入输出
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n,n) {
        int a,b,distance;
        E = n * (n - 1) / 2;
        while (E--) {
            cin >> a >> b >> distance;
            connect add;
            add.v = b;
            add.dis = distance;
            Adj[a].push_back(add);
            // 无向图反向添加一次
            add.v = a;
            Adj[b].push_back(add);
        }
        // 输出结果
        cout << Prim() << endl;
        // 清空容器
        for (int i = 1;i <= n;++i) {
            Adj[i].clear();
        }
    }
    return 0;
}
