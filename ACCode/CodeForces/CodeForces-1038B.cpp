#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int N;
    scanf("%d", &N);
    if (N <= 2) {
        printf("No\n");
    }
    else {
        printf("Yes\n");
        if (N & 1) {
            int Num = (N - 1) / 2 + 1;
            if (Num & 1) {
                printf("%d %d\n", 1, (N + 1) / 2);
                printf("%d ", N - 1);
                for (int i = 1; i <= N; ++i) {
                    if (i == (N + 1) / 2) {
                        continue;
                    }
                    printf("%d ", i);
                }
                printf("\n");
            }
            else {
                printf("%d ", (N + 1) / 2);
                for (int i = 1; i <= N; i += 2) {
                    printf("%d ", i);
                }
                printf("\n");
                printf("%d ", N / 2);
                for (int i = 2; i <= N; i += 2) {
                    printf("%d ", i);
                }
                printf("\n");
            }
        }
        else {
            printf("%d ", N / 2);
            for (int i = 1; i < N; i += 2) {
                printf("%d ", i);
            }
            printf("\n");
            printf("%d ", N / 2);
            for (int i = 2; i <= N; i += 2) {
                printf("%d ", i);
            }
            printf("\n");
        }
    }
    return 0;
}

