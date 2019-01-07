#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N, M; Case <= T; ++Case) {
        scanf("%d%d", &N, &M);
        int X = (M - 2 * N) / 2;
        int Y = N - X;
        printf("%d %d\n", X, Y);
    }
    return 0;
}

