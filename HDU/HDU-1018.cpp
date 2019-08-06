#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
const double e = 2.718281828459;

int Stirling(int x) {
    if (x <= 1) {
        return 1;
    }
    return int(ceil(log10(2 * pi * x) / 2 + x * log10(x / e)));
}

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 0, X; Case < T; ++Case) {
        scanf("%d", &X);
        printf("%d\n", Stirling(X));
    }
    return 0;
}

