#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, A, B; Case <= T; ++Case) {
        scanf("%d%d", &A, &B);
        printf("%d\n", A + B);
    }
    return 0;
}
