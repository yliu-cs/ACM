#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e1 + 5;

long long Digit[maxn];
long long Dp[maxn][maxn << 12];

bool Judge(long long Statu) {
    long long Cnt[maxn];
    for (int i = 0; i < 10; ++i) {
        Cnt[i] = Statu % 3;
        Statu /= 3;
        if (Cnt[i]) {
            if (i & 1) {
                if (Cnt[i] == 1) {
                    return false;
                }
            }
            else {
                if (Cnt[i] == 2) {
                    return false;
                }
            }
        }
    }
    return true;
}

long long UpdateStatu(long long New, long long Statu) {
    long long Cnt[maxn];
    for (int i = 0; i < 10; ++i) {
        Cnt[i] = Statu % 3;
        Statu /= 3;
    }
    if (Cnt[New]) {
        Cnt[New] = 3 - Cnt[New];
    }
    else {
        Cnt[New] = 1;
    }
    long long NewStatu = 0;
    for (int i = 9; i >= 0; --i) {
        NewStatu *= 3;
        NewStatu += Cnt[i];
    }
    return NewStatu;
}

long long Dfs(long long Site, long long Statu, bool Pre, bool Limit) {
    if (Site == 0) {
        return Judge(Statu);
    }
    if (!Limit && ~Dp[Site][Statu]) {
        return Dp[Site][Statu];
    }
    long long Max = Limit ? Digit[Site] : 9;
    long long Ans = 0;
    for (int i = 0; i <= Max; ++i) {
        long long NowStatu = (Pre && i == 0) ? 0 : UpdateStatu(i, Statu);
        Ans += Dfs(Site - 1, NowStatu, Pre && i == 0, Limit && i == Max);
    }
    if (!Limit) {
        Dp[Site][Statu] = Ans;
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
    long long T;
    scanf("%lld", &T);
    for (long long Case = 1, L, R; Case <= T; ++Case) {
        scanf("%lld%lld", &L, &R);
        printf("%lld\n", Cal(R) - Cal(L - 1));
    }
    return 0;
}
