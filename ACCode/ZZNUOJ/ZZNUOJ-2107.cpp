#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e2 + 5;

int Height[maxn << 10];
int Dp[maxn << 10][maxn];

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N, X; Case <= T; ++Case) {
        scanf("%d%d", &N, &X);
        int Max = 0;
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &Height[i]);
            Max = max(Max, Height[i]);
        }
        for (int j = Height[1]; j <= Max; ++j) {
            Dp[1][j] = (j - Height[1]) * (j - Height[1]);
        }
        int Ans = INF;
        for (int i = 2; i <= N; ++i) {
            for (int j = Height[i]; j <= Max; ++j) {
                Dp[i][j] = INF;
                for (int k = Height[i - 1]; k <= Max; ++k) {
                    Dp[i][j] = min(abs(j - k) * X + Dp[i - 1][k], Dp[i][j]);
                }
                Dp[i][j] += (j - Height[i]) * (j - Height[i]);
                if (i == N) {
                    Ans = min(Ans, Dp[i][j]);
                }
            }
        }
        printf("%d\n", Ans);
    }
    return 0;
}
