#include <bits/stdc++.h>

const int INF = "Edit";
const int maxn = "Edit";

struct Link {
    // U、V:顶点，Dis:边权
    int U, V;
    int Dis;
};
// 松弛更新数组
int Dis[maxn];
// 边
std::vector<Link> edges;

// Bellman_Ford算法判断是否存在负环回路
bool BellmanFord(int Start, int N) {
    memset(Dis, INF, sizeof(Dis));
    Dis[Start] = 0;
    // 最多做N-1次
    for (int i = 1; i < N; ++i) {
        bool flag = false;
        for (int j = 0; j < int(edges.size()); ++j) {
            if (Dis[edges[j].V] > Dis[edges[j].U] + edges[j].Dis) {
                Dis[edges[j].V] = Dis[edges[j].U] + edges[j].Dis;
                flag = true;
            }
        }
        // 没有负环回路
        if (!flag) {
            return true;
        }
    }
    // 有负环回路
    for (int j = 0; j < int(edges.size()); ++j) {
        if (Dis[edges[j].V] > Dis[edges[j].U] + edges[j].Dis) {
            return false;
        }
    }
    // 没有负环回路
    return true;
}
