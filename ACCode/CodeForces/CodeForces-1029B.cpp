#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1, 0), dp(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] <= a[i - 1] * 2) {
            dp[i] = dp[i - 1] + 1;
        }
        ans = dp[i] > ans ? dp[i] : ans;
    }
    std::cout << ans << std::endl;
    return 0;
}

