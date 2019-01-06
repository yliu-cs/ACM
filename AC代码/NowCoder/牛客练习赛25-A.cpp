#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    int q;
    scanf("%d", &q);
    for (int Query = 1, n; Query <= q; ++Query) {
        scanf("%d", &n);
        long long ans = 0;
        int i  = 1;
        while (i <= n) {
            int last = n / (n / i);
            ans += (n / i) * (last - i + 1);
            i = last + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

