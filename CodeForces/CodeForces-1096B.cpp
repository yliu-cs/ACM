#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxn = 2e5 + 5;

long long QuickMul(long long A, long long B) {
    long long Ans = 0;
    while (B) {
        if (B & 1) {
            Ans = (Ans + A) % mod;
        }
        A = (A + A) % mod;
        B >>= 1;
    }
    return Ans;
}

int N;
char Str[maxn];
long long Left, Right;

int main(int argc, char *argv[]) {
    scanf("%d%s", &N, Str + 1);
    int Left = 1, Right = N;
    for (int i = 2; i <= N; ++i) {
        if (Str[i] != Str[i - 1]) {
            Left = i;
            break;
        }
    }
    for (int i = N - 1; i >= 1; --i) {
        if (Str[i] != Str[i + 1]) {
            Right = i;
            break;
        }
    }
    Right = (N - Right) + 1;
    if (Str[1] == Str[N]) {
        printf("%lld\n", QuickMul(Left, Right));
    }
    else {
        printf("%lld\n", ((Left + Right) % (long long)mod - 1 * 1LL + (long long)mod) % (long long)mod);
    }
    return 0;
}

