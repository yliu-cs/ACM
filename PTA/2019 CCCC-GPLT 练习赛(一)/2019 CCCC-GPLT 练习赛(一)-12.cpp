#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

bool IsPrime[maxn];
vector<int> Prime;

void Sieve() {
    memset(IsPrime, true, sizeof(IsPrime));
    for (long long i = 2; i < maxn; ++i) {
        if (IsPrime[i]) {
            Prime.push_back(i);
            for (long long j = i * i; j < maxn; j += i) {
                IsPrime[j] = false;
            }
        }
    }
}

int M;

int main(int argc, char *argv[]) {
    Sieve();
    scanf("%d", &M);
    int Index = lower_bound(Prime.begin(), Prime.end(), M) - Prime.begin();
    for (int i = Index - 1, k = 0; i >= 0 && k < 10; --i, ++k) {
        printf("%6d", Prime[i]);
    }
    return 0;
}

