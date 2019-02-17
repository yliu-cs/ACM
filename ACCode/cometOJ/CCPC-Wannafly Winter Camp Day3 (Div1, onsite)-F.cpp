#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 5;
const int mod = 998244353;

bool IsPrime[maxn];
int Tot;
int Prime[maxn];
int Mu[maxn];
long long PrefixMu[maxn];
long long PrefixF[maxn];

void Sieve() {
    for (int i = 2; i < maxn; ++i) IsPrime[i] = true;
    Mu[1] = 1; PrefixF[1] = 1;
    for (long long i = 2; i < maxn; ++i) {
        if (IsPrime[i]) {
            Mu[i] = -1;
            PrefixF[i] = -2;
            Prime[Tot++] = i;
        }
        for (long long j = 0; j < Tot && i * Prime[j] < maxn; ++j) {
            IsPrime[i * Prime[j]] = false;
            Mu[i * Prime[j]] = -Mu[i];
            if (i % Prime[j] == 0) {
                Mu[i * Prime[j]] = 0;
                if ((i / Prime[j]) % Prime[j] == 0) PrefixF[i * Prime[j]] = 0;
                else PrefixF[i * Prime[j]] = PrefixF[i / Prime[j]];
                break;
            }
            else PrefixF[i * Prime[j]] = -2 * PrefixF[i];
        }
    }
    for (int i = 1; i < maxn; ++i) {
        PrefixMu[i] = (PrefixMu[i - 1] + Mu[i]) % mod;
        PrefixF[i] = (PrefixF[i - 1] + PrefixF[i]) % mod;
    }
}

long long __mod(long long Key1, long long Key2) {
    long long Ans = Key1 - Key2;
    while (Ans < 0) Ans += mod;
    return Ans % mod;
}

map<long long, long long> SumMu;

long long SigmaMu(long long Key) {
    if (Key < maxn) return PrefixMu[Key];
    if (SumMu[Key]) return SumMu[Key];
    long long Ans = 1;
    for (long long l = 2, tp; l <= Key; l = tp + 1) {
        tp = Key / (Key / l);
        Ans -= (tp - l + 1) * SigmaMu(Key / l);
    }
    SumMu[Key] = Ans;
    return SumMu[Key];
}

map<long long, long long> SumF;

long long SigmaF(long long Key) {
    if (Key < maxn) return PrefixF[Key];
    if (SumF[Key]) return SumF[Key];
    long long Ans = SigmaMu(Key);
    for (long long l = 2, tp; l <= Key; l = tp + 1) {
        tp = Key / (Key / l);
        Ans = __mod(Ans, (tp - l + 1) * SigmaF(Key / l) % mod);
    }
    SumF[Key] = Ans;
    return Ans;
}

long long Cal(long long Key) {
    long long Ans = 0;
    for (long long l = 1, tp; l <= Key; l = tp + 1) {
        tp = Key / (Key / l);
        Ans = (Ans + __mod(SigmaF(tp), SigmaF(l - 1)) * (Key / l) % mod * (Key / l) % mod) % mod;
    }
    return Ans;
}

long long N;

int main(int argc, char *argv[]) {
    Sieve();
    scanf("%lld", &N);
    printf("%lld\n", Cal(N));
    return 0;
}

