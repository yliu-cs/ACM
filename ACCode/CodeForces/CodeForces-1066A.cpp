#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, L, v, l, r; Case <= T; ++Case) {
        scanf("%d%d%d%d", &L, &v, &l, &r);
        int Ans = L / v;
        Ans -= r / v - l / v + (l % v == 0);
        printf("%d\n", Ans);
    }
    return 0;
}
