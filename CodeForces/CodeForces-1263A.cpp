#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::vector<int> a(3);
        for (int i = 0; i < 3; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        if (a[0] + a[1] >= a[2]) {
            int lst = (a[0] + a[1] - a[2]) / 2;
            lst = std::min(lst, a[0]);
            std::cout << a[2] + lst << '\n';
        }
        else {
            std::cout << a[0] + a[1] << '\n';
        }
    }
    return 0;
}