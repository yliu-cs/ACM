#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e1 + 5;

long long L, R, K;
long long Digit[maxn];
long long Dp[maxn][1 << 10][maxn];

long long UpdateStatu(long long New, long long Statu) {
    for (int i = New; i < 10; ++i) {
        if (Statu & (1 << i)) {
            return (Statu ^ (1 << i)) | (1 << New);
        }
    }
    return Statu | (1 << New);
}

long long CntStatu(long long X) {
    long long Ans = 0;
    while (X) {
        if (X & 1) {
            Ans++;
        }
        X >>= 1;
    }
    return Ans;
}

long long Dfs(long long Site, long long Statu, bool Pre, bool Limit) {
    if (Site == 0) {
        return CntStatu(Statu) == K;
    }
    if (!Limit && ~Dp[Site][Statu][K]) {
        return Dp[Site][Statu][K];
    }
    long long Max = Limit ? Digit[Site] : 9;
    long long Ans = 0;
    for (int i = 0; i <= Max; ++i) {
        long long NowStatu = (Pre && i == 0) ? 0 : UpdateStatu(i, Statu);
        Ans += Dfs(Site - 1, NowStatu, Pre && (i == 0), Limit && i == Max);
    }
    if (!Limit) {
        Dp[Site][Statu][K] = Ans;
    }
    return Ans;
}

long long Cal(long long X) {
    long long Len = 0;
    while (X) {
        Digit[++Len] = X % 10;
        X /= 10;
    }
    return Dfs(Len, 0, true, true);
}

int main(int argc, char *argv[]) {
    memset(Dp, -1, sizeof(Dp));
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%lld%lld%lld", &L, &R, &K);
        printf("Case #%d: %lld\n", Case, Cal(R) - Cal(L - 1));
    }
    return 0;
}
