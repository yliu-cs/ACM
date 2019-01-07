#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N, K; Case <= T; ++Case) {
        scanf("%d%d", &N, &K);
        printf("Case %d: ", Case);
        if (K == 1) {
            if (N & 1) {
                printf("first\n");
            }
            else {
                printf("second\n");
            }
        }
        else {
            if (N <= K) {
                printf("first\n");
            }
            else {
                printf("second\n");
            }
        }
    }
    return 0;
}
