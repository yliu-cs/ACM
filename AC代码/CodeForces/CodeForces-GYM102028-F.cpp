#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 5;

struct Status {
    int X, Y, Step;
};

int T;
int R, C;
int N, M;
int Len;
int StartX, StartY;
int EndX, EndY;
char Plat[maxn][maxn];
int Vis[maxn][maxn];
int DX[6] = {1, 1, -1, -1, 2, -2};
int DY[6] = {3, -3, 3, -3, 0, 0};

int Bfs() {
    queue<Status> Que;
    Que.push(Status {StartX, StartY, 1});
    Vis[StartX][StartY] = 0;
    while (!Que.empty()) {
        Status Cur = Que.front(); Que.pop();
        if (Cur.X == EndX && Cur.Y == EndY) {
            return Cur.Step;
        }
        for (int i = 0; i < 6; ++i) {
            int NX = Cur.X + DX[i], NY = Cur.Y + DY[i];
            if (NX >= 0 && NX < N && NY >= 0 && NY < M && Plat[NX][NY] == ' ') {
                int NNX = NX + DX[i], NNY = NY + DY[i];
                if (NNX >= 0 && NNX < N && NNY >= 0 && NNY < M && Cur.Step + 1 < Vis[NNX][NNY]) {
                    Que.push(Status {NNX, NNY, Cur.Step + 1});
                    Vis[NNX][NNY] = Cur.Step + 1;
                }
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d%d", &R, &C);
        N = 4 * R + 3, M = 6 * C + 3;
        getchar();
        for (int i = 0; i < N; ++i) {
            fgets(Plat[i], maxn, stdin);
            Len = strlen(Plat[i]);
            if (Plat[i][Len - 1] == '\n') {
                Plat[i][Len - 1] = '\0';
            }
            for (int j = 0; j < M; ++j) {
                Vis[i][j] = INF;
                if (Plat[i][j] == 'S') {
                    StartX = i; StartY = j;
                }
                if (Plat[i][j] == 'T') {
                    EndX = i; EndY = j;
                }
            }
        }
        printf("%d\n", Bfs());
    }
    return 0;
}

