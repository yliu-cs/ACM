#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int N, M, K;
int B[maxn];
ll Seg[maxn];
ll Ans;

int main(int argc, char *argv[]) {
    scanf("%d%d%d", &N, &M, &K);
    if (N == 1) {
        printf("1\n");
        return 0;
    }
    for (int i = 0; i < N; ++i) scanf("%d", &B[i]);
    for (int i = 1; i < N; ++i) Seg[i] = B[i] - B[i - 1];
    sort(Seg + 1, Seg + N);
    for (int i = 1; i < N - (K - 1); ++i) Ans += Seg[i];
    printf("%lld\n", Ans + K);
    return 0;
}

