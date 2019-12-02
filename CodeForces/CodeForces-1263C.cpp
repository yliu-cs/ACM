#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> ans;
        for (int l = 1, r; l <= n; l = r + 1) {
            r = n / (n / l);
            ans.push_back(n / l);
        }
        ans.push_back(0);
        std::sort(ans.begin(), ans.end());
        std::cout << ans.size() << '\n';
        for (int i = 0; i < (int)ans.size(); ++i) {
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}