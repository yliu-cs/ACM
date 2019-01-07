#include <bits/stdc++.h>

const int maxn = "Edit";

int Dp[2][1 << maxn];

void Update(int Cur, int A, int B) {
    if (B & (1 << M)) {
        Dp[Cur][B ^ (1 << M)] = Dp[Cur][B ^ (1 << M)] + Dp[Cur ^ 1][A];
    }
}

// 轮廓线Dp(1*2在N*M图上摆放数)
int Contour(int N, int M) {
    memset(Dp, 0, sizeof(Dp));
    int Cur = 0;
    Dp[Cur][(1 << M) - 1] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            Cur ^= 1;
            memset(Dp[Cur], 0, sizeof(Dp[Cur]));
            for (int k = 0; k < (1 << M); ++k) {
                Update(Cur, k, k << 1);
                if (i && !(k & (1 << (M - 1)))) {
                    Update(Cur, k, (k << 1) ^ (1 << M) ^ 1);
                }
                if (j && (!(k & 1))) {
                    Update(Cur, k, (k << 1) ^ 3);
                }
            }
        }
    }
    return Dp[Cur][(1 << M) - 1];
}

