#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;

int N;
int M[maxn][maxn];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        for (int k = 0; k < N - i; ++k) printf(" ");
        for (int j = 1; j <= i; ++j) {
            if (j == 1 || j == i) {
                printf("%4d", 1);
                M[i][j] = 1;
                continue;
            }
            M[i][j] = M[i - 1][j - 1] + M[i - 1][j];
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}

