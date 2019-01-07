#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N; Case <= T; ++Case) {
        scanf("%d", &N);
        int Sum = 0, Cnt = 0;
        for (int i = 0, X; i < N; ++i) {
            scanf("%d", &X);
            Sum += abs(X);
            if (X > 0) {
                Cnt++;
            }
        }
        int Gcd = __gcd(Sum, Cnt);
        Sum /= Gcd;
        Cnt /= Gcd;
        printf("Case %d: ", Case);
        if (Cnt == 0) {
            printf("inf\n");
        }
        else {
            printf("%d/%d\n", Sum, Cnt);
        }
    }
    return 0;
}
