#include<bits/stdc++.h>
using namespace std;

int Sgn(long long X) {
    return X == 0 ? 0 : (X < 0 ? -1 : 1);
}

int main(int argc, char *argv[]) {
    long long X1, Y1, X2, Y2;
    scanf("%lld%lld%lld%lld", &X1, &Y1, &X2, &Y2);
    int N;
    scanf("%d", &N);
    int Ans = 0;
    for (int i = 1; i <= N; ++i) {
        long long A, B, C;
        scanf("%lld%lld%lld", &A, &B, &C);
        if (Sgn(X1 * A + Y1 * B + C) * Sgn(X2 * A + Y2 * B + C) < 0) {
            Ans++;
        }
    }
    printf("%d\n", Ans);
    return 0;
}

