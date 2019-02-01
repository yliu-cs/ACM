#include <bits/stdc++.h>
using namespace std;

const long long maxn = 2e6 + 5;
const long long mod = 998244353;

long long QuickPow(long long A, long long B) {
    long long Ans = 1;
    while (B) {
        if (B & 1) Ans = Ans * A % mod;
        A = A * A % mod;
        B >>= 1;
    }
    return Ans;
}

long long Factorial[maxn];
long long FactorialInv[maxn];

void FactorialInvInit() {
    Factorial[0] = 1;
    for (long long i = 1; i < maxn; ++i) {
        Factorial[i] = (Factorial[i - 1] * i) % mod;
    }
    FactorialInv[maxn - 1] = QuickPow(Factorial[maxn - 1], mod - 2);
    for (long long i = maxn - 2; i >= 0; --i) {
        FactorialInv[i] = (FactorialInv[i + 1] * (i + 1)) % mod;
    }
}

long long C(long long N, long long M) {
    if (N < 0 || M < 0 || N < M) return 0;
    return Factorial[N] * FactorialInv[M] % mod * FactorialInv[N - M] % mod;
}

long long N, M, K;
long long Ans, Temp, Cur;

int main(int argc, char *argv[]) {
    FactorialInvInit();
    scanf("%lld%lld%lld", &N, &M, &K);
    Ans = 0; Temp = 1; Cur = K / 2;
    for (long long i = Cur + 1; i <= Cur + N + M - 1; ++i) Temp = Temp * i % mod;
    for (long long i = 0; i <= N; ++i) {
        if ((K - i) % 2 == 0) {
            Ans = (Ans + (C(N, i) * ((K - i) % 2 ? -1 : 1) * Temp) % mod) % mod;
            Temp = Temp * Cur % mod * QuickPow(Cur + N + M - 1, mod - 2) % mod;
            Cur--;
        }
    }
    Ans = (Ans * FactorialInv[N + M -1] % mod + mod) % mod;
    printf("%lld\n", Ans);
    return 0;
}

