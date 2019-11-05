#include<stdio.h>
#define LL long long
#define nmax 100
int modular_exp(int a, LL b) {
    int res;
    res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % nmax;
        }
        a = a * a % nmax;
        b >>= 1;
    }
    return res;
}

int main() {
    int t, i;
    LL n;
    while (scanf("%d", &t) != EOF,t) {
        for (i = 1; i <= t; i++) {
            scanf("%I64d", &n);
            printf("Case %d: %d\n", i,
                    (modular_exp(4, n - 1) + modular_exp(2, n - 1)) % nmax);
        }
        printf("\n");
    }
    return 0;
}
