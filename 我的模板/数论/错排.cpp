#include <bits/stdc++.h>

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

// Staggered:错排数
long long Staggered[maxn];

// 求错排数
void StaggeredInit() {
    Staggered[1] = 0;
    Staggered[2] = 1;
    // 递推求错排数
    for (int i = 3; i < maxn; ++i) {
        Staggered[i] = (i - 1) * (Staggered[i - 1] + Staggered[i - 2]) % mod;
    }
}

