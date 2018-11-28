#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(int argc, char *argv[]) {
    long long T;
    scanf("%lld", &T);
    for (long long Case = 1, N, Ans; Case <= T; ++Case) {
        scanf("%lld", &N);
        Ans = (((N + 3) * (N + 2) % mod) * (N + 1) % mod) * N % mod;
        Ans = Ans * 41666667 % mod;
        printf("%lld\n", Ans);
    }
    return 0;
}

