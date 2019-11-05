#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    vector<int> A(N, 0);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    long long Ans = 0, Sum = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (Sum + A[i] <= K) {
            Sum += A[i];
        }
        else {
            Sum = A[i];
            M--;
        }
        if (!M) {
            break;
        }
        Ans++;
    }
    printf("%lld\n", Ans);
    return 0;
}

