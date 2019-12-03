#include <bits/stdc++.h>

const int INF = 1e9 + 5;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::pair<int, int> ans = {INF, a[0]};
        for (int i = 0; i + k < n; ++i) {
            int m = (a[i] + a[i + k]) / 2;
            int dis = std::max(m - a[i], a[i + k] - m);
            ans = std::min(ans, {dis, m});
        }
        std::cout << ans.second << '\n';
    }
    return 0;
}