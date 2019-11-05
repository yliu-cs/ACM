#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int Q;
    scanf("%d", &Q);
    for (int Query = 1; Query <= Q; ++Query) {
        long long N, M, K, Ans = 0;
        scanf("%lld%lld%lld", &N, &M, &K);
        if (max(N, M) > K) {
            printf("-1\n");
        }
        else {
            if ((max(N, M) - min(N, M)) % 2 == 0 && (K - min(N, N)) % 2 == 1) {
                K -= 2;
                N--; M--;
            }
            Ans = min(N, M);
            K -= min(N, M);
            int Lave = max(N, M) - min(N, M);
            if (Lave & 1) {
                Lave--;
                K--;
                Ans += K;
            }
            else {
                Ans += K;
            }
            printf("%lld\n", Ans);
        }
    }
    return 0;
}

