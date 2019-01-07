#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N, M, Max, Min; Case <= T; ++Case) {
        scanf("%d%d", &N, &M);
        Max = Min = M;
        for (int i = 1; i <= M; ++i) {
            int Temp = (M + i - 1) / i - 1 + M;
            if (Temp <= N) {
                Min = i;
                break;
            }
        }
        printf("%d %d\n", Max, Min);
    }
    return 0;
}

