#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string a, b;
    std::cin >> a >> b;
    std::vector<int> pre((int)a.length(), 0);
    for (int i = 0; i < (int)a.length(); ++i) {
        pre[i] = (i == 0 ? 0 : pre[i - 1]) + (a[i] == '1');
    }
    int cnt = 0;
    for (auto &c : b) {
        cnt += (c == '1');
    }
    int ans = 0;
    for (int i = (int)b.length() - 1; i < (int)a.length(); ++i) {
        int sum = pre[i] - (i - (int)b.length() < 0 ? 0 : pre[i - (int)b.length()]);
        if (std::abs(sum - cnt) % 2 == 0) {
            ++ans;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
