#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e1 + 5;

int N;
set<int> S[maxn];
int K;
int Cnt;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1, M; i <= N; ++i) {
        scanf("%d", &M);
        for (int j = 0, X; j < M; ++j) {
            scanf("%d", &X);
            S[i].insert(X);
        }
    }
    scanf("%d", &K);
    for (int i = 0, X, Y; i < K; ++i) {
        scanf("%d%d", &X, &Y);
        Cnt = 0;
        for (auto it : S[Y])
            if (S[X].find(it) != S[X].end())
                Cnt++;
        printf("%.2lf%\n", (double)Cnt / (double)(S[X].size() + S[Y].size() - Cnt) * 100.0);
    }
    return 0;
}

