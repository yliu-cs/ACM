#include <bits/stdc++.h>

typedef long long ll;
const int maxn = "Edit";

bool is_prime[maxn];
vector<int> prime

void Sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < maxn; ++i) {
        if (is_prime[i]) prime.emplace_back(i);
        for (auto &it : prime) {
            if (it * i >= maxn) break;
            is_prime[i * it] = false;
        }
    }
}

