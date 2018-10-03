#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    long long mx = 1e18, ans = 1e18;
    for (long long i = 1; i * i <= (a + b); ++i) {
        // 更新a可围最大面积长边边长
        if (a % i == 0) {
            mx = min(mx, a / i);
        }
        // 更新b可围最大面积长边边长
        if (b % i == 0) {
            mx = min(mx, b / i);
        }
        // 若总数可围且能包含a、b，更新结果
        if ((a + b) % i == 0 && (a + b) / i >= mx) {
            ans = min(ans, 2 * (i + ((a + b) / i)));
        }
    }
    printf("%lld\n", ans);
    return 0;
}

