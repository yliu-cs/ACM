#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        std::vector<long long> a(n);
        std::map<long long, long long> cnt;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            ++cnt[a[i]];
        }
        a.erase(std::unique(a.begin(), a.end()), a.end());
        std::vector<long long> pre((int)a.size(), 0);
        pre[0] = cnt[a[0]];
        for (int i = 1; i < (int)a.size(); ++i) {
            pre[i] = pre[i - 1] + cnt[a[i]];
        }
        auto idx = std::upper_bound(pre.begin(), pre.end(), n / 2);
        if (idx == pre.begin()) {
            std::cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
            continue;
        }
        --idx;
        long long g = pre[0];
        auto idx1 = std::upper_bound(pre.begin(), pre.end(), 2ll * g);
        long long s = (*idx1) - g;
        long long h = (*idx) - g - s;
        if (g >= s || g >= h || h < 0) {
            g = s = h = 0;
        }
        std::cout << g << ' ' << s << ' ' << h << '\n';
    }
    return 0;
}