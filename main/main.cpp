#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 5;

int N, M;
int Tot;
long long Number[maxn];
long long Ans;

int Gcd(int A, int B) {
    return B ? Gcd(B, A % B) : A;
}

void Dfs(int Cur, int Cnt, int Lcm) {
    Lcm = Number[Cur] / Gcd(Number[Cur], Lcm) * Lcm;
    if (Cnt & 1) {
        Ans += (N - 1) / Lcm;
    }
    else {
        Ans -= (N - 1) / Lcm;
    }
    for (int i = Cur + 1; i < Tot; ++i) {
        Dfs(i, Cnt + 1, Lcm);
    }
}

int main(int argc, char *argv[]) {
    while (~scanf("%d%d", &N, &M)) {
        Tot = 1;
        for (int i = 1, X; i <= M; ++i) {
            scanf("%d", &X);
            if (X != 0) {
                Number[Tot++] = X;
            }
        }
        Ans = 0;
        for (int i = 1; i < Tot; ++i) {
            Dfs(i, 1, Number[i]);
        }
        printf("%lld\n", Ans);
    }
    return 0;
}

