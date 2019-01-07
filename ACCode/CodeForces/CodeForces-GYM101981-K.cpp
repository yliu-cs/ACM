#include <bits/stdc++.h>
using namespace std;

int N, M;

int main(int argc, char *argv[]) {
    srand(time(NULL));
    scanf("%d%d", &N, &M);
    for (int i = 0, X; i < N; ++i) {
        for (int j = 0;j < M; ++j) {
            scanf("%d", &X);
        }
    }
    char Operate[4] = {'U', 'D', 'L', 'R'};
    for (int i = 0; i < 5e4; ++i) {
        printf("%c", Operate[rand() % 4]);
    }
    return 0;
}

