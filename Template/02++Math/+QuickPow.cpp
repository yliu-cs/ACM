#include <bits/stdc++.h>

const int mod = 1e9 + 7;

// 快速乘求A*B%mod
long long QuickMul(long long A, long long B) {
    long long Ans = 0;
    while (B) {
        if (B & 1) {
            Ans = (Ans + A) % mod;
        }
        A = (A + A) % mod;
        B >>= 1;
    }
    return Ans;
}

// 快速幂求A^B%mod
long long QuickPow(long long A, long long B) {
    long long Ans = 1;
    while (B) {
        if (B & 1) {
            // Ans = Ans * A % mod;
            Ans = QuickMul(Ans, A) % mod;
        }
        // A = A * A % mod;
        A = QuickMul(A, A) % mod;
        B >>= 1;
    }
    return Ans;
}
