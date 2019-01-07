#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e1 + 5;

long long Digit[maxn];
long long Dp[maxn][maxn][maxn << 7];

long long Dfs(long long Site, long long Pivot, long long Torqueses, bool Limit) {
    if (Site == 0) {
        return Torqueses == 0;
    }
    if (!Limit && ~Dp[Site][Pivot][Torqueses]) {
        return Dp[Site][Pivot][Torqueses];
    }
    long long Max = Limit ? Digit[Site] : 9;
    long long Ans = 0;
    for (int i = 0; i <= Max; ++i) {
        long long NowTorqueses = Torqueses + (Site - Pivot) * i;
        if (NowTorqueses >= 0) {
            Ans += Dfs(Site - 1, Pivot, NowTorqueses, Limit && i == Max);
        }
    }
    if (!Limit) {
        Dp[Site][Pivot][Torqueses] = Ans;
    }
    return Ans;
}

long long Cal(long long X) {
    long long Len = 0;
    while (X) {
        Digit[++Len] = X % 10;
        X /= 10;
    }
    long long Ans = 0;
    // 枚举轴心
    for (int i = 1; i <= Len; ++i) {
        Ans += Dfs(Len, i, 0, 1);
    }
    return Ans - Len + 1;
}

int main(int argc, char *argv[]) {
    memset(Dp, -1, sizeof(Dp));
    long long T;
    scanf("%lld", &T);
    for (long long Case = 1, X, Y; Case <= T; ++Case) {
        scanf("%lld%lld", &X, &Y);
        printf("%lld\n", Cal(Y) - Cal(X - 1));
    }
    return 0;
}
