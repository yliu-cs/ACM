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

void Dfs(int Cur, int Cnt, int Limit, long long LCM) {
    if (Cnt == Limit) {
        if (Limit & 1) {
            Ans += (N - 1) / LCM;
        }
        else {
            Ans -= (N - 1) / LCM;
        }
        return;
    }
    if (Cur >= Tot) {
        return;
    }
    long long NowLCM = LCM == -1 ? Number[Cur] : LCM;
    Dfs(Cur + 1, Cnt + 1, Limit, Number[Cur] / Gcd(Number[Cur], NowLCM) * NowLCM);
    Dfs(Cur + 1, Cnt, Limit, LCM);
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
            Dfs(1, 0, i, -1);
        }
        printf("%lld\n", Ans);
    }
    return 0;
}

