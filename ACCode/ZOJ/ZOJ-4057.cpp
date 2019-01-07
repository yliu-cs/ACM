#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N; Case <= T; ++Case) {
        scanf("%d", &N);
        map<int, int> Cnt;
        int Ans = 0;
        for (int i = 0, X; i < N; ++i) {
            scanf("%d", &X);
            if (X == 0) {
                continue;
            }
            int Digit = log2(X) + 1;
            Cnt[Digit]++;
            Ans = max(Ans, Cnt[Digit]);
        }
        printf("%d\n", Ans);
    }
    return 0;
}

