#include <bits/stdc++.h>
using namespace std;

int X, Y, Z;
int A, B, C;

int main(int argc, char *argv[]) {
    scanf("%d%d%d", &X, &Y, &Z);
    scanf("%d%d%d", &A, &B, &C);
    if (A < X) {
        printf("NO\n");
        return 0;
    }
    A -= X;
    if (A + B < Y) {
        printf("NO\n");
        return 0;
    }
    if (A >= Y) A -= Y;
    else {
        Y -= A;
        A = 0;
        B -= Y;
    }
    Y = 0;
    if (A + B + C < Z) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}

