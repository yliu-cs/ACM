#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int N, K;
    scanf("%d%d", &N, &K);
    if (N == 0) {
        printf("Austin\n");
    }
    else if (K >= N) {
        printf("Adrien\n");
    }
    else {
        if (N & 1) {
            printf("Adrien\n");
        }
        else {
            if (K == 1) {
                printf("Austin\n");
            }
            else {
                printf("Adrien\n");
            }
        }
    }
    return 0;
}

