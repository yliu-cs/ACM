#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e1 + 5;

int N, M, C;
int T[maxn][maxn];
int XS, YS;
int XT, YT;
int Dp[maxn][maxn][20010];

void Transfer(int X, int Y, int Time) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (abs(i) == abs(j)) {
                if (i != 0 && j != 0) {
                    continue;
                }
            }
            Dp[X][Y][Time] = max(Dp[X][Y][Time], Dp[X + i][Y + j][Time - 1]);
        }
    }
    Dp[X][Y][Time] += Time % T[X][Y] == 0;
}

int main(int argc, char *argv[]) {
    scanf("%d%d%d", &N, &M, &C);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &T[i][j]);
        }
    }
    scanf("%d%d%d%d", &XS, &YS, &XT, &YT);
    for (int k = 1; k < 20010; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (k == 0) Dp[i][j][k] = 0;
                else if ((abs(i - XS) + abs(j - YS) <= k)) Transfer(i, j, k);
            }
        }
    }
    for (int i = 0; i < 20010; ++i) {
        if (Dp[XT][YT][i] >= C) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
