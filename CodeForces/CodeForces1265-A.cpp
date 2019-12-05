#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int n = (int)s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                for (int j = 0; j < 3; ++j) {
                    if (i != 0 && s[i - 1] == (char)(j + 'a')) {
                        continue;
                    }
                    if (i != n - 1 && s[i + 1] == (char)(j + 'a')) {
                        continue;
                    }
                    s[i] = (char)(j + 'a');
                    break;
                }
            }
        }
        bool f = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                f = false;
            }
            if (i > 0) {
                if (s[i] == s[i - 1]) {
                    f = false;
                }
            }
        }
        if (f) {
            std::cout << s << '\n';
        }
        else {
            std::cout << -1 << '\n';
        }
    }
    return 0;
}