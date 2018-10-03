#include <bits/stdc++.h>

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

long long Inv[maxn];

// 递推求逆元
void InvInit() {
    Inv[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        Inv[i] = (mod - mod / i) * Inv[mod % i] % mod;
    }
}
