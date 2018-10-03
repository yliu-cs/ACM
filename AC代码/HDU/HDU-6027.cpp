#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long QuickMul(long long A, long long B, long long M) {
    long long Res = 0;
    while (B) {
        if (B & 1) {
            Res = (Res + A) % M;
        }
        A = (A + A) % M;
        B >>= 1;
    }
    return Res;
}

long long QuickPow(long long A, long long B, long long M) {
    long long Res = 1;
    while (B) {
        if (B & 1) {
            Res = QuickMul(Res, A, M) % M;
        }
        A = QuickMul(A, A, M) % M;
        B >>= 1;
    }
    return Res;
}

int main(int argc, char *argv[]) {
    int t;
    scanf("%d", &t);
    for (int Case = 1; Case <= t; ++Case) {
        long long n, k;
        scanf("%lld%lld", &n, &k);
        long long Ans = 1;
        for (long long i = 2; i <= n; ++i) {
            Ans = (Ans + QuickPow(i, k, mod)) % mod;
        }
        printf("%lld\n", Ans);
    }
    return 0;
}

