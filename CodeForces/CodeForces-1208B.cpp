#include <bits/stdc++.h>
const int inf = 1e9 + 5;
int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::set<int> set;
    int ans = inf;
    for (int l = 1; l <= n; ++l) {
        std::set<int> st;
        for (int r = n; r >= l; --r) {
            if (st.find(a[r]) != st.end() || set.find(a[r]) != set.end()) {
                ans = std::min(ans, r - l + 1);
                break;
            }
            st.insert(a[r]);
        }
        if (set.find(a[l]) != set.end()) break;
        set.insert(a[l]);
    }
    ans = ans == inf ? 0 : ans;
    std::cout << ans << '\n';
    return 0;
}