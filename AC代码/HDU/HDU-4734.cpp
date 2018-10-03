#include <bits/stdc++.h>
using namespace std;

const int maxn = 30;

long long Digit[maxn];
long long Dp[maxn][maxn << 10];

long long F(long long X) {
    long long Ans = 0;
    long long Len = 0;
    while (X) {
        Ans += (X % 10) * (1 << Len++);
        X /= 10;
    }
    return Ans;
}

long long Dfs(long long Site, long long Sum, bool Flag) {
    if (Site == 0) {
        return Sum >= 0;
    }
    if (!Flag && ~Dp[Site][Sum]) {
        return Dp[Site][Sum];
    }
    long long Max = Flag ? Digit[Site] : 9;
    long long Ans = 0;
    for (int i = 0; i <= Max; ++i) {
        long long NowSum = Sum - i * (1 << (Site - 1));
        if (NowSum >= 0) {
            Ans += Dfs(Site - 1, NowSum, Flag && i == Max);
        }
    }
    if (!Flag) {
        Dp[Site][Sum] = Ans;
    }
    return Ans;
}

long long Cal(long long A, long long B) {
    long long Len = 0;
    while (B) {
        Digit[++Len] = B % 10;
        B /= 10;
    }
    memset(Dp, -1, sizeof(Dp));
    return Dfs(Len, F(A), true);
}

int main(int argc, char *argv[]) {
    freopen("in.txt", "r", stdin);
    long long T;
    scanf("%lld", &T);
    for (long long Case = 1, A, B; Case <= T; ++Case) {
        scanf("%lld%lld", &A, &B);
        printf("Case #%lld: %lld\n", Case, Cal(A, B));
    }
    return 0;
}
