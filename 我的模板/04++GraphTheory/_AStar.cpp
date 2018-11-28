#include <bits/stdc++.h>

const int INF = "Edit";
const int maxn = "Edit";

struct Link {
    int V, Weight, Next;
};

Link edges[maxn << 1];
int Head[maxn];
int Tot;
// 反向边
Link Reverseedges[maxn << 1];
int ReverseHead[maxn];
int ReverseTot;

// 链式前向星存图初始化
void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
    ReverseTot = 0;
    memset(ReverseHead, -1, sizeof(ReverseHead));
}

// 加边建图
void AddEdge(int U, int V, int Weight) {
    edges[Tot] = Link {V, Weight, Head[U]};
    Head[U] = Tot++;
    // 用反向边另建图
    Reverseedges[ReverseTot] = Link {U, Weight, ReverseHead[V]};
    ReverseHead[V] = ReverseTot++;
}

int Dis[maxn];

struct Cmp {
    bool operator() (const int &A, const int &B) {
        return Dis[A] > Dis[B];
    }
};

// 利用反向边图求各点到终点的最短路
void Dijkstra(int Start) {
    priority_queue<int, vector<int>, Cmp> Que;
    memset(Dis, INF, sizeof(Dis));
    Dis[Start] = 0;
    Que.push(Start);
    while (!Que.empty()) {
        int U = Que.top(); Que.pop();
        for (int i = ReverseHead[U]; i != -1; i = Reverseedges[i].Next) {
            if (Dis[Reverseedges[i].V] > Dis[U] + Reverseedges[i].Weight) {
                Dis[Reverseedges[i].V] = Dis[U] + Reverseedges[i].Weight;
                Que.push(Reverseedges[i].V);
            }
        }
    }
}

struct AStarNode {
    int F, G, Point;
    // A*核心:F=G+H(Point)，这里H(Point)=Dis[Point]
    bool operator < (const AStarNode &A) const {
        if (F == A.F) {
            return G > A.G;
        }
        return F > A.F;
    }
};

// A*算法求起点Start到终点End的第K短路
int AStar(int Start, int End, int K) {
    int Cnt = 0;
    priority_queue<AStarNode> Que;
    // 注意特盘相同点是否算最短路
    if (Start == End) {
        K++;
    }
    // 起点与终点不连通
    if (Dis[Start] == INF) {
        return -1;
    }
    Que.push(AStarNode {Dis[Start], 0, Start});
    while (!Que.empty()) {
        AStarNode Keep = Que.top(); Que.pop();
        if (Keep.Point == End) {
            Cnt++;
            if (Cnt == K) {
                // 返回第K短路长度
                return Keep.G;
            }
        }
        for (int i = Head[Keep.Point]; i != -1; i = edges[i].Next) {
            AStarNode Temp;
            Temp.Point = edges[i].V;
            Temp.G = Keep.G + edges[i].Weight;
            Temp.F = Temp.G + Dis[Temp.Point];
            Que.push(Temp);
        }
    }
    return -1;
}
