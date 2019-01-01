#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 5;

long long Phi(long long X) {
    long long Ans = X;
    for (long long i = 2; i * i <= X; ++i) {
        if (!(X % i)) {
            Ans = Ans / i * (i - 1);
            while (!(X % i)) {
                X /= i;
            }
        }
    }
    if (X > 1) {
        Ans = Ans / X * (X - 1);
    }
    return Ans;
}

int main(int argc, char *argv[]) {
    long long X;
    scanf("%lld", &X);
    long long Ans = 0;
    for (long long i = 1; i * i <= X; ++i) {
        if (X % i == 0) {
            if (i * i == X) {
                Ans += i * Phi(X / i);
            }
            else {
                Ans += i * Phi(X / i) + (X / i) * Phi(i);
            }
        }
    }
    printf("%lld\n", Ans);
    return 0;
}

