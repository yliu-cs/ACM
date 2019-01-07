#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int N, K;
    scanf("%d%d", &N, &K);
    int Scope = K * 2 + 1;
    int Cnt = N / Scope;
    int Judge = N - Cnt * Scope;
    if (Scope >= N) {
        if (K >= N) {
            printf("%d\n", 1);
            printf("%d", 1);
        }
        else {
            printf("%d\n", 1);
            printf("%d", K + 1);
        }
    }
    else if (Judge == 0) {
        printf("%d\n", Cnt);
        for (int i = K + 1, k = 1; k <= Cnt; i += Scope, ++k) {
            printf("%d ", i);
        }
    }
    else if (Judge >= K + 1 && Judge < Scope) {
        printf("%d\n", Cnt + 1);
        printf("%d ", Judge - K);
        for (int i = Judge - K + Scope, k = 1; k <= Cnt; i += Scope, ++k) {
            printf("%d ", i);
        }
    }
    else if (Judge < K + 1) {
        Cnt--;
        Judge += Scope;
        int A = 0, B = 0;
        while (A < K + 1 && Judge > 0) {
            A++;
            Judge--;
        }
        while (B < K + 1 && Judge > 0) {
            B++;
            Judge--;
        }
        if (Judge > 0) {
            while (A < Scope && Judge > 0) {
                A++;
                Judge--;
            }
            while (B < Scope && Judge > 0) {
                B++;
                Judge--;
            }
        }
        printf("%d\n", Cnt + 2);
        printf("%d ", A - K);
        for (int i = A - K + Scope, k = 1; k <= Cnt; i += Scope, ++k) {
            printf("%d ", i);
        }
        printf("%d ", N - (B - K) + 1);
    }
    printf("\n");
    return 0;
}

