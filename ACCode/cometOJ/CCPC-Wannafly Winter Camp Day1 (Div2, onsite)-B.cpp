#include <bits/stdc++.h>
using namespace std;

struct Point {
    int X, Y;
};

int N, M, C;
int T[15][15];
Point Start, End;
int Dp[10180][15][15];
int Ans;

void Transfer(int Time, int X, int Y) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (abs(i) == abs(j) && i != 0 && j != 0) {
                continue;
            }
            Dp[Time][X][Y] = max(Dp[Time][X][Y], Dp[Time - 1][X + i][Y + j]);
            if (Time % T[X][Y] == 0) {
                Dp[Time][X][Y]++;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d%d%d", &N, &M, &C);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &T[i][j]);
        }
    }
    scanf("%d%d", &Start.X, &Start.Y);
    scanf("%d%d", &End.X, &End.Y);
    memset(Dp, 0, sizeof(Dp));
    for (int l = 1; l <= 10180; ++l) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (abs(i - Start.X) + abs(j - Start.Y) > l) {
                    continue;
                }
                Transfer(l, i, j);
            }
        }
    }
    for (int i = 1; i <= 10180; ++i) {
        if (Dp[i][End.X][End.Y] >= C) {
            Ans = i;
            break;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
