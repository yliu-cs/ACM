#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int N;
ll C[maxn];
ll T[maxn];
ll CDiff[maxn];
ll TDiff[maxn];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%lld", &C[i]);
    for (int i = 1; i <= N; ++i) scanf("%lld", &T[i]);
    if (C[1] != T[1] || C[N] != T[N]) {
        printf("No\n");
        return 0;
    }
    for (int i = 2; i <= N; ++i) CDiff[i] = C[i] - C[i - 1];
    for (int i = 2; i <= N; ++i) TDiff[i] = T[i] - T[i - 1];
    sort(CDiff + 2, CDiff + N + 1);
    sort(TDiff + 2, TDiff + N + 1);
    for (int i = 2; i <= N; ++i) {
        if (CDiff[i] != TDiff[i]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}

