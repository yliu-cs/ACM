#include <bits/stdc++.h>

const int maxn = "Edit"

bool IsPrime[maxn];
vector<int> PrimeFactor[maxn];

void Init() {
    memset(IsPrime, true, sizeof(IsPrime));
    for (long long i = 2; i < maxn; ++i) {
        if (IsPrime[i]) {
            PrimeFactor[i].push_back(i);
            for (long long j = i + i; j < maxn; ++j) {
                IsPrime[j] = false;
                PrimeFactor[j].push_back(i);
            }
        }
    }
    IsPrime[1] = false;
}

