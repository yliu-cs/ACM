#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

long long N, Q, S, T;
long long Ans;
long long A[maxn];

long long Get(long long X) {
    return X > 0 ? -(X * S) : ((-X) * T);
}

int main(int argc, char *argv[]) {
    scanf("%lld%lld%lld%lld", &N, &Q, &S, &T);
    Ans = 0;
    for (long long i = 0, Last = 0, X; i <= N; ++i) {
        scanf("%lld", &X);
        A[i] = X - Last;
        Last = X;
        Ans += Get(A[i]);
    }
    for (long long i = 1, L, R, X; i <= Q; ++i) {
        scanf("%lld%lld%lld", &L, &R, &X);
        Ans -= Get(A[L]);
        A[L] += X;
        Ans += Get(A[L]);
        if (R != N) {
            Ans -= Get(A[R + 1]);
            A[R + 1] -= X;
            Ans += Get(A[R + 1]);
        }
        printf("%lld\n", Ans);
    }
    return 0;
}

