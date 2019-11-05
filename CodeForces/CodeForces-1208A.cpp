#include <bits/stdc++.h>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b, n;
        std::cin >> a >> b >> n;
        long long f[3] = {a, b, a ^ b};
        std::cout << f[n % 3] << '\n';
    }
    return 0;
}