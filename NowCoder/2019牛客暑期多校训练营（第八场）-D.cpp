#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int n, m, h, q;
struct point { int x, y, z; };
int d[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
int dis[maxn];
int Get(int x, int y, int z) {
    return (z - 1) * n * m + (x - 1) * m + y;
}
std::vector<point> tag, que;
void Bfs() {
    for (int i = 1; i <= n * m * h; ++i) dis[i] = inf;
    for (auto &p : tag) dis[Get(p.x, p.y, p.z)] = 0;
    que = tag;
    for (size_t idx = 0; idx < que.size(); ++idx) {
        int x = que[idx].x, y = que[idx].y, z = que[idx].z, id = Get(x, y, z);
        for (int i = 0; i < 6; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1], nz = z + d[i][2];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && nz >= 1 && nz <= h && dis[Get(nx, ny, nz)] == inf) {
                dis[Get(nx, ny, nz)] = dis[id] + 1;
                que.push_back((point){nx, ny, nz});
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &h, &q);
    for (int i = 1; i <= n * m * h; ++i) dis[i] = inf;
    int e = std::sqrt(n * m * h);
    std::vector<point> buf;
    for (int i = 1, op, x, y, z; i <= q; ++i) {
        scanf("%d%d%d%d", &op, &x, &y, &z);
        if (op == 1) {
            buf.push_back((point){x, y, z});
            if (buf.size() == e) {
                for (auto &p : buf) tag.push_back(p);
                buf.clear();
                Bfs();
            }
        }
        else {
            int ans = dis[Get(x, y, z)];
            for (auto &p : buf) ans = std::min(ans, std::abs(p.x - x) + std::abs(p.y - y) + std::abs(p.z - z));
            printf("%d\n", ans);
        }
    }
    return 0;
}