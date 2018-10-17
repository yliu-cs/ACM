#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N; Case <= T; ++Case) {
        scanf("%d", &N);
        printf("%d\n", (1 << __builtin_popcount(N)));
    }
    return 0;
}
