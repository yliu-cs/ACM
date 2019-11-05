#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n, L, a;
    scanf("%d%d%d", &n, &L, &a);
    int Keep = 0, Ans = 0;
    for (int i = 0, t, l; i < n; ++i) {
        scanf("%d%d", &t, &l);
        Ans += (t - Keep) / a;
        Keep = t + l;
    }
    Ans += (L - Keep) / a;
    printf("%d\n", Ans);
    return 0;
}
