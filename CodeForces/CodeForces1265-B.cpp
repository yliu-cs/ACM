#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::vector<int> idx(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            --a[i];
            idx[a[i]] = i;
        }
        std::vector<int> ans(n, 0);
        int l = idx[0], r = idx[0];
        for (int i = 0; i < n; ++i) {
            l = std::min(l, idx[i]);
            r = std::max(r, idx[i]);
            if (r - l + 1 == i + 1) {
                ans[i] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            std::cout << ans[i];
        }
        std::cout << '\n';
    }
    return 0;
}