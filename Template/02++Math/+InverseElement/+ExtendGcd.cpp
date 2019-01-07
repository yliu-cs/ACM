#include <bits/stdc++.h>

// 扩展欧几里得，A*X+B*Y=D
long long ExtendGcd(long long A, long long B, long long &X, long long &Y) {
    // 无最大公约数
    if (A == 0 && B == 0) {
        return -1;
    }
    if (B == 0) {
        X = 1;
        Y = 0;
        return A;
    }
    long long D = ExtendGcd(B, A % B, Y, X);
    Y -= A / B * X;
    return D;
}

// 逆元，AX = 1(mod M)
long long Inv(long long A, long long N) {
    long long X, Y;
    long long D = ExtendGcd(A, N, X, Y);
    if (D == 1) {
        return (X % N + N) % N;
    }
    else {
        return -1;
    }
}

