#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
ll K;
ll X, Y;

int main(int argc, char *argv[]) {
    scanf("%lld%lld%lld", &N, &M, &K);
    if (K / __gcd(N * M, K) > 2) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    printf("0 0\n");
    X = 2 * N / __gcd(2 * N, K);
    Y = M / (K / __gcd(2 * N, K));
    if (X > N) {
        Y = 2 * M / __gcd(2 * M, K);
        X = N / (K / __gcd(2 * M, K));
    }
    printf("%lld 0\n", X);
    printf("0 %lld\n", Y);
    return 0;
}

