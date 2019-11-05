#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 5;
const int INF = 0x3f3f3f3f;

int N;
int C[maxn];
int Dp[maxn][maxn];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%d", &C[i]);
    N = unique(C + 1, C + N + 1) - C - 1;
    for (int k = 1; k <= N; ++k) {
        for (int l = 0; l <= N; ++l) {
            int r = l + k;
            if (C[l] == C[r]) Dp[l][r] = Dp[l + 1][r - 1] + 1;
            else Dp[l][r] = min(Dp[l][r - 1], Dp[l + 1][r]) + 1;
        }
    }
    printf("%d\n", Dp[1][N]);
    return 0;
}
