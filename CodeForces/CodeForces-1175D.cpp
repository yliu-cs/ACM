#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    long long sum = 0;
    std::vector<long long> suf;
    for (int i = n - 1; i >= 0; --i) {
        sum += a[i];
        if (i > 0) {
            suf.push_back(sum);
        }
    }
    std::sort(suf.begin(), suf.end(),
        [&](long long k1, long long k2) {
        return k1 > k2;
    });
    for (int i = 0; i < k - 1; ++i) {
        sum += suf[i];
    }
    std::cout << sum << '\n';
    return 0;
}