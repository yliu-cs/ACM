#include <bits/stdc++.h>

const int maxn = 1e5 + 5;

// N:顶点数
int N;
// Dis[i][j]为i点到j点的最短路
int Dis[maxn][maxn];

// Floyd算法
void Floyd() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                Dis[i][j] = std::min(Dis[i][j], Dis[i][k] + Dis[k][j]);
            }
        }
    }
}
