#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int N, X, Y;
    scanf("%d%d%d", &N, &X, &Y);
    if (X > Y) {
        printf("%d\n", N);
        return 0;
    }
    int Cnt = 0;
    vector<int> A(N, 0);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        if (A[i] <= X) {
            Cnt++;
        }
    }
    printf("%d\n", (Cnt + 1) / 2);
    return 0;
}
