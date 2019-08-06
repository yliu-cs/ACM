#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e6 + 5;

bool IsPrime[maxn];
int Tot;
int Prime[maxn];
ll Mu[maxn], Phi[maxn];
map<int, ll> SumMu, SumPhi;

void Sieve() {
    Mu[1] = Phi[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        if (!IsPrime[i]) {
            Prime[Tot++] = i;
            Phi[i] = i - 1;
            Mu[i] = -1;
        }
        for (int j = 0; j < Tot && i * Prime[j] < maxn; ++j) {
            IsPrime[i * Prime[j]] = true;
            if (i % Prime[j] == 0) {
                Phi[i * Prime[j]] = Phi[i] * Prime[j];
                break;
            }
            Phi[i * Prime[j]] = Phi[i] * Phi[Prime[j]];
            Mu[i * Prime[j]] = -Mu[i];
        }
    }
    for (int i = 1; i < maxn; ++i) {
        Mu[i] += Mu[i - 1];
        Phi[i] += Phi[i - 1];
    }
}

ll SigmaMu(int Key) {
    if (Key < maxn) return Mu[Key];
    if (SumMu.find(Key) != SumMu.end()) return SumMu[Key];
    ll Ans = 1;
    for (int l = 2, tp; l <= Key; l = tp + 1) {
        tp = Key / (Key / l);
        Ans -= (tp - l + 1) * SigmaMu(Key / l);
    }
    SumMu[Key] = Ans;
    return SumMu[Key];
}

ll SigmaPhi(int Key) {
    if (Key < maxn) return Phi[Key];
    if (SumPhi.find(Key) != SumPhi.end()) return SumPhi[Key];
    ll Ans = (ll)Key * (ll)(Key + 1) / (ll)2;
    for (int l = 2, tp; l <= Key; l = tp + 1) {
        tp = Key / (Key / l);
        Ans -= (tp - l + 1) * SigmaPhi(Key / l);
    }
    SumPhi[Key] = Ans;
    return SumPhi[Key];
}

int T;
ll N;

int main(int argc, char *argv[]) {
    Sieve();
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%lld", &N);
        printf("%lld %lld\n", SigmaPhi(N), SigmaMu(N));
    }
    return 0;
}

