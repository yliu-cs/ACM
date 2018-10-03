#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
const int mod = 2520;

long long Index[mod + 5];
long long Digit[maxn];
long long Dp[maxn][mod + 5][maxn];

void Init() {
    int Num = 0;
    for (int i = 1; i <= mod; ++i) {
        if (mod % i == 0) {
            Index[i] = Num++;
        }
    }
    memset(Dp, -1, sizeof(Dp));
}

// 最小公倍数
inline long long __Lcm(long long A, long long B) {
    return (A * B) / __gcd(A, B);
}

// 深搜，Len:当前位，Sum:之前位对2520的模，Lcm:之前位的最小公倍数，Flag:前位是否达上限
long long Dfs(int Len, int Mod, int Lcm, bool Flag) {
    // 搜到最后一位
    if (Len == 0) {
        return Mod % Lcm == 0;
    }
    if (!Flag && ~Dp[Len][Mod][Index[Lcm]]) {
        return Dp[Len][Mod][Index[Lcm]];
    }
    long long Ans = 0;
    // 当前位可达的最大数
    int Up = Flag ? Digit[Len] : 9;
    // 枚举当前位所有可能数
    for (long long i = 0; i <= Up; ++i) {
        long long NowLcm = Lcm;
        if (i) {
            NowLcm = __Lcm(NowLcm, i);
        }
        Ans += Dfs(Len - 1, (Mod * 10 + i) % mod, NowLcm, Flag && i == Up);
    }
    return Flag ? Ans : Dp[Len][Mod][Index[Lcm]] = Ans;
}

long long Cal(long long X) {
    // 数字按位分解
    int Len = 0;
    while (X) {
        Digit[++Len] = X % 10;
        X /= 10;
    }
    return Dfs(Len, 0, 1, 1);
}

int main(int argc, char *argv[]) {
    Init();
    long long T;
    scanf("%lld", &T);
    for (long long Case = 1, Left, Right; Case <= T; ++Case) {
        scanf("%lld%lld", &Left, &Right);
        printf("%lld\n", Cal(Right) - Cal(Left - 1));
    }
    return 0;
}
