#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N; Case <= T; ++Case) {
        scanf("%d", &N);
        int Ans = 0;
        for (int i = 0, X; i < N; ++i) {
            scanf("%d", &X);
            Ans ^= X;
        }
        if (Ans) {
            printf("Liu_B is sure to win.\n");
        }
        else {
            printf("Liu_B is not sure to win.\n");
        }
    }
    return 0;
}
