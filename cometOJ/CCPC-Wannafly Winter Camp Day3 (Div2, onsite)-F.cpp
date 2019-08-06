#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e7 + 5;
const int mod = 998244353;

bool IsPrime[maxn];
int Tot;
int Prime[maxn];
int Mu[maxn];
ll Prefix[maxn];

void Sieve() {
    for (int i = 2; i < maxn; ++i) IsPrime[i] = true;
    Mu[1] = 1;
    for (ll i = 2; i < maxn; ++i) {
        if (IsPrime[i]) {
            Mu[i] = -1;
            Prime[Tot++] = i;
        }
        for (ll j = 0; j < Tot && i * Prime[j] < maxn; ++j) {
            IsPrime[i * Prime[j]] = false;
            if (i % Prime[j] == 0) {
                Mu[i * Prime[j]] = 0;
                break;
            }
            Mu[i * Prime[j]] = -Mu[i];
        }
    }
    for (ll i = 1; i < maxn; ++i)
        Prefix[i] = (Prefix[i - 1] + Mu[i]) % mod;
}

ll CalF(ll Key) {
    ll Ans = 0;
    for (ll l = 1, tp; l <= Key; l = tp + 1) {
        tp = Key / (Key / l);
        Ans = (Ans + (Prefix[tp] - Prefix[l - 1] + mod) % mod * (Key / l) % mod * (Key / l) % mod) % mod;
    }
    return Ans;
}

ll CalAns(ll Key) {
    ll Ans = 0;
    for (ll l = 1, tp; l <= Key; l = tp + 1) {
        tp = Key / (Key / l);
        Ans = (Ans + (Prefix[tp] - Prefix[l - 1] + mod) * CalF(Key / l) % mod) % mod;
    }
    return Ans;
}

ll N;

int main(int argc, char *argv[]) {
    Sieve();
    scanf("%lld", &N);
    printf("%lld\n", CalAns(N));
    return 0;
}

