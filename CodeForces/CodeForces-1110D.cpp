#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int N, M;
int Cnt[maxn];
int Dp[maxn][5][5];

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 1, X; i <= N; ++i) {
        scanf("%d", &X);
        Cnt[X]++;
    }
    for (int a = 0; a <= M; ++a) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (i + j + k <= Cnt[a]) {
                        Dp[a + 1][j][k] = max(Dp[a + 1][j][k], Dp[a][i][j] + k + (Cnt[a] - i - j - k) / 3);
                    }
                }
            }
        }
    }
    printf("%d\n", Dp[M + 1][0][0]);
    return 0;
}

