#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    if (m < n || k < n) {
        std::cout << "No" << '\n';
    }
    else {
        std::cout << "Yes" << '\n';
    }
    return 0;
}
