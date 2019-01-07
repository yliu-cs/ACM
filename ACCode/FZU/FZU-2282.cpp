#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;

long long Staggered[maxn];

void StaggeredInit() {
    Staggered[0] = 1;
    Staggered[1] = 0;
    Staggered[2] = 1;
    for (int i = 3; i < maxn; ++i) {
        Staggered[i] = (i - 1) * (Staggered[i - 1] + Staggered[i - 2]) % mod;
    }
}

long long QuickMul(long long A, long long B) {
    long long Res = 0;
    while (B) {
        if (B & 1) {
            Res = (Res + A) % mod;
        }
        A = (A + A) % mod;
        B >>= 1;
    }
    return Res;
}

long long QuickPow(long long A, long long B) {
    long long Res = 1;
    while (B) {
        if (B & 1) {
            Res = QuickMul(Res, A) % mod;
        }
        A = QuickMul(A, A) % mod;
        B >>= 1;
    }
    return Res;
}

long long Factorial[maxn], FactorialInv[maxn];

void FactorialInvInit() {
    Factorial[0] = 0;
    Factorial[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        Factorial[i] = (Factorial[i - 1] * i) % mod;
    }
    FactorialInv[maxn - 1] = QuickPow(Factorial[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; --i) {
        FactorialInv[i] = (FactorialInv[i + 1] * (i + 1)) % mod;
    }
}

int main(int argc, char *argv[]) {
    StaggeredInit();
    FactorialInvInit();
    int T;
    scanf("%d", &T);
    for (int Case = 1, N, K; Case <= T; ++Case) {
        scanf("%d%d", &N, &K);
        long long Ans = 0;
        for (int i = K; i <= N; ++i) {
            Ans = (Ans + (((Factorial[N] * FactorialInv[i]) % mod * FactorialInv[N - i]) % mod * Staggered[N - i]) % mod) % mod;
        }
        printf("%lld\n", Ans);
    }
    return 0;
}

