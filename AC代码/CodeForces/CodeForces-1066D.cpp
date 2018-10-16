#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

int N, M, K;
int A[maxn];

bool Check(int X) {
    int Vis = 0;
    while (Vis < M && X <= N) {
        int Temp = K;
        while (X <= N && A[X] <= Temp) {
            Temp -= A[X++];
        }
        Vis++;
    }
    return X == N + 1 ? true : false;
}

int main(int argc, char *argv[]) {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }
    int Ans = 0;
    int Left = 1, Right = N;
    while (Left <= Right) {
        int Mid = (Left + Right) >> 1;
        if (Check(Mid)) {
            Ans = max(Ans, N - Mid + 1);
            Right = Mid - 1;
        }
        else {
            Left = Mid + 1;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
