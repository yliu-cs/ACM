#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        long long ans = 0;
        while (n >= k) {
            ans += n - n / k * k;
            n = n / k * k;
            n /= k;
            ++ans;
        }
        while (n) {
            --n;
            ++ans;
        }
        std::cout << ans << '\n';
    }
    return 0;
}