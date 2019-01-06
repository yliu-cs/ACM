#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;

int N, M;
int Ans;
int R[maxn];
int D[maxn], S[maxn], T[maxn];
int Difference[maxn];
int Sum[maxn];

bool Check(int X) {
    memset(Difference, 0, sizeof(Difference));
    for (int i = 1; i <= X; ++i) {
        Difference[S[i]] += D[i];
        Difference[T[i] + 1] -= D[i];
    }
    Sum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        Sum[i] = Sum[i - 1] + Difference[i];
        if (Sum[i] > R[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &R[i]);
    }
    for (int i = 1; i <= M; ++i) {
        scanf("%d%d%d", &D[i], &S[i], &T[i]);
    }
    int Left = 1, Right = M;
    Ans = INF;
    while (Left <= Right) {
        int Mid = (Left + Right) >> 1;
        if (Check(Mid)) {
            Left = Mid + 1;
        }
        else {
            Ans = Mid;
            Right = Mid - 1;
        }
    }
    if (Ans == INF) {
        printf("0\n");
    }
    else {
        printf("-1\n%d\n", Ans);
    }
    return 0;
}

