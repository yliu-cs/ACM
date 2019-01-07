#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int N;
    while (~scanf("%d", &N) && N) {
        int Cur = 0, Ans = N * 5;
        for (int i = 0, X; i < N; ++i) {
            scanf("%d", &X);
            if (X > Cur) {
                Ans += 6 * (X - Cur);
            }
            else {
                Ans += 4 * (Cur - X);
            }
            Cur = X;
        }
        printf("%d\n", Ans);
    }
    return 0;
}
