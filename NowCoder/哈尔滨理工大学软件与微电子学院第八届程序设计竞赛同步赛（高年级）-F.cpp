#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e2 + 5;

struct Status {
    int X, Y;
    int Step;
};

int N, M, K;
long long Dp[maxn][maxn][maxn];
bool Vis[maxn][maxn][maxn];
int DX[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int DY[8] = {1, -1, 1, -1, 2, 2, -2, -2};

long long Bfs() {
    memset(Dp, 0, sizeof(Dp));
    memset(Vis, false, sizeof(Vis));
    queue<Status> Que;
    Que.push(Status {0, 0, 0});
    Vis[0][0][0] = true;
    Dp[0][0][0] = 1;
    while (!Que.empty()) {
        Status Cur = Que.front(); Que.pop();
        if (Cur.Step == K) {
            continue;
        }
        for (int i = 0; i < 8; ++i) {
            int NX = Cur.X + DX[i], NY = Cur.Y + DY[i];
            if (NX >= 0 && NX < N && NY >= 0 && NY < M) {
                Dp[NX][NY][Cur.Step + 1] += Dp[Cur.X][Cur.Y][Cur.Step];
                Dp[NX][NY][Cur.Step + 1] %= mod;
                if (Vis[NX][NY][Cur.Step + 1]) {
                    continue;
                }
                Que.push(Status {NX, NY, Cur.Step + 1});
                Vis[NX][NY][Cur.Step + 1] = true;
            }
        }
    }
    return Dp[N - 1][M - 1][K];
}

int main(int argc, char *argv[]) {
    while (~scanf("%d%d%d", &N, &M, &K)) {
        printf("%lld\n", Bfs());
    }
    return 0;
}

