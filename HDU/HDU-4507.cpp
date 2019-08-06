#include <bits/stdc++.h>
using namespace std;

const long long maxn = 3e1 + 5;
const long long mod = 1e9 + 7;

struct Info {
    // Cnt:与7无关的个数，Sum:与7无关的数字和，SqrtSum:与7无关数的平方和
    long long Cnt, Sum, SquareSum;
};

long long Digit[maxn];
long long Pos[maxn];
Info Dp[maxn][maxn][maxn];

void Init() {
    Pos[0] = 0;
    Pos[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        Pos[i] = (Pos[i - 1] * 10) % mod;
    }
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            for (int k = 0; k < maxn; ++k) {
                Dp[i][j][k].Cnt = -1;
            }
        }
    }
}

// Site:数位，Sum:高位和模7，Mod:模7，Limit:高位是否达上限
Info Dfs(long long Site, long long Sum, long long Mod, bool Limit) {
    if (Site == 0) {
        return Info {Sum != 0 && Mod != 0, 0, 0};
    }
    if (!Limit && ~Dp[Site][Sum][Mod].Cnt) {
        return Dp[Site][Sum][Mod];
    }
    long long Max = Limit ? Digit[Site] : 9;
    Info Ans = Info {0, 0, 0};
    for (int i = 0; i <= Max; ++i) {
        if (i != 7) {
            long long NowSum = (Sum + i) % 7, NowMod = (Mod * 10 + i) % 7;
            Info Temp = Dfs(Site - 1, NowSum, NowMod, Limit && i == Max);
            Ans.Cnt = (Ans.Cnt + Temp.Cnt) % mod;
            Ans.Sum = (Ans.Sum + (Temp.Sum + (((Pos[Site] * i) % mod) * Temp.Cnt) % mod) % mod) % mod;
            Ans.SquareSum = (Ans.SquareSum + (Temp.SquareSum + ((2 * Pos[Site] * i) % mod) * Temp.Sum) % mod) % mod;
            Ans.SquareSum = (Ans.SquareSum + ((((Temp.Cnt * Pos[Site]) % mod * Pos[Site]) % mod) * i * i) % mod) % mod;
        }
    }
    if (!Limit) {
        Dp[Site][Sum][Mod] = Ans;
    }
    return Ans;
}

long long Cal(long long X) {
    long long Len = 0;
    while (X) {
        Digit[++Len] = X % 10;
        X /= 10;
    }
    return Dfs(Len, 0, 0, true).SquareSum;
}

int main(int argc, char *argv[]) {
    freopen("in.txt", "r", stdin);
    Init();
    long long T;
    scanf("%lld", &T);
    for (long long Case = 1, L, R; Case <= T; ++Case) {
        scanf("%lld%lld", &L, &R);
        printf("%lld\n", ((Cal(R) - Cal(L - 1)) % mod + mod) % mod);
    }
    return 0;
}
