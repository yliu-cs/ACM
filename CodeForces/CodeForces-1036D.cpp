#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int N;
    scanf("%d", &N);
    vector<long long> A(N);
    long long SumA = 0;
    set<long long> S;
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i]);
        SumA += A[i];
        S.insert(SumA);
    }
    int M;
    scanf("%d", &M);
    vector<long long> B(M);
    long long SumB = 0, Ans = 0;
    for (int i = 0; i < M; ++i) {
        scanf("%lld", &B[i]);
        SumB += B[i];
        Ans += S.count(SumB);
    }
    Ans = SumA != SumB ? -1 : Ans;
    printf("%lld\n", Ans);
    return 0;
}

