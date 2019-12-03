#include <bits/stdc++.h>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a == 1 && b == 0 && c == 0) {
        std::cout << "YES" << '\n';
        std::cout << 0 << '\n';
    }
    else if (b == 0 && c == 0) {
        std::cout << "YES" << '\n';
        std::cout << 1 << '\n';
    }
    else if (a > b + 1) {
        std::cout << "YES" << '\n';
        std::cout << b + c + 1 << '\n';
    }
    else {
        std::cout << "NO" << '\n';
    }
    return 0;
}
