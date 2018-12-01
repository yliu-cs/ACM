#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    long long N, M;
    scanf("%lld%lld", &N, &M);
    if (N < M) {
        swap(N, M);
    }
    long long NX = N / 7, MX = M / 7;
    long long Ans = NX * MX * 7;
    Ans += (N % 7) * MX;
    Ans += (M % 7) * NX;
    for (int i = 1; i <= N % 7; ++i) {
        for (int j = 1; j <= M % 7; ++j) {
            if ((i + j) % 7 == 0) {
                Ans++;
            }
        }
    }
    printf("%lld\n", Ans);
    return 0;
}
