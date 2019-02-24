#include <bits/stdc++.h>
using namespace std;

map<int, int> Cnt;

int main(int argc, char *argv[]) {
    for (int i = 0, X; i < 10; ++i) {
        scanf("%d", &X);
        Cnt[i] = X;
    }
    if (Cnt[0] != 0) {
        for (int i = 1; i <= 9; ++i) {
            if (Cnt[i] != 0) {
                printf("%d", i);
                Cnt[i]--;
                break;
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (Cnt[i] == 0) continue;
        for (int j = 0; j < Cnt[i]; ++j)
            printf("%d", i);
    }
    return 0;
}

