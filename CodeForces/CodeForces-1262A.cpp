#include <bits/stdc++.h>

const int INF = (int)(1e9 + 7);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int maxl = -INF, minr = INF;
        for (int i = 0; i < n; ++i) {
            int l, r;
            std::cin >> l >> r;
            minr = std::min(minr, r);
            maxl = std::max(maxl, l);
        }
        if (minr <= maxl) {
            std::cout << maxl - minr << '\n';
        }
        else {
            std::cout << 0 << '\n';
        }
    }
    return 0;
}
