#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e6 + 5;

bool IsPrime[maxn];
int Tot;
int Prime[maxn];
int Mu[maxn];
ll PrefixMu[maxn];

void Sieve() {
    for (int i = 2; i < maxn; ++i) IsPrime[i] = true;
    Mu[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        if (IsPrime[i]) {
            Prime[Tot++] = i;
            Mu[i] = -1;
        }
        for (int j = 0; j < Tot && i * Prime[j] < maxn; ++j) {
            IsPrime[i * Prime[j]] = false;
            if (i % Prime[j] == 0) {
                Mu[i % Prime[j]] = 0;
                break;
            }
            Mu[i * Prime[j]] = -Mu[i];
        }
    }
    for (int i = 1; i < maxn; ++i) PrefixMu[i] = PrefixMu[i - 1] + Mu[i];
}

map<ll, ll> SumMu;

ll SigmaMu(ll Key) {
    if (Key < maxn) return PrefixMu[Key];
    if (SumMu[Key]) return SumMu[Key];
    ll Ans = 1;
    for (ll l = 2, tp; l <= Key; l = tp + 1) {
        tp = Key / (Key / l);
        Ans -= (tp - l + 1) * SigmaMu(Key / l);
    }
    SumMu[Key] = Ans;
    return SumMu[Key];
}

ll A, B;

int main(int argc, char *argv[]) {
    Sieve();
    scanf("%lld%lld", &A, &B);
    printf("%lld\n", SigmaMu(B) - SigmaMu(A- 1));
    return 0;
}

