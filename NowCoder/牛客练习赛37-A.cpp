#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;

bool IsPrime[maxn];
int Tot;
int PrimeYear[maxn];
int Month[6] = {1, 2, 3, 10, 11, 12};
int Day[6] = {10, 20, 30, 1, 11, 21};

void PrimeInit() {
    for (int i = 0; i < maxn; ++i) {
        IsPrime[i] = true;
    }
    Tot = 1;
    for (long long i = 2; i < maxn; ++i) {
        if (IsPrime[i]) {
            if (i >= 2000) {
                PrimeYear[Tot++]= i;
            }
            for (long long j = i * i; j < maxn; j += i) {
                IsPrime[j] = false;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    PrimeInit();
    int N;
    scanf("%d", &N);
    for (int i = 0, K; i < N; ++i) {
        scanf("%d", &K);
        int Index = (K + 5) / 6;
        printf("%d-", PrimeYear[Index]);
        Index = (K - 1) % 6;
        printf("%02d-%02d\n", Month[Index], Day[Index]);
    }
    return 0;
}
