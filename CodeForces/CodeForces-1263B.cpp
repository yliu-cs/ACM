#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::string> pin(n);
        std::set<std::string> set;
        for (int i = 0; i < n; ++i) {
            std::cin >> pin[i];
            set.insert(pin[i]);
        }
        std::set<std::string> fi;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (fi.find(pin[i]) == fi.end()) {
                fi.insert(pin[i]);
                continue;
            }
            ++ans;
            bool f = false;
            for (int idx = 0; idx < 4; ++idx) {
                for (int j = 0; j < 10; ++j) {
                    std::string buf = pin[i];
                    buf[idx] = (char)(j + '0');
                    if (set.find(buf) == set.end()) {
                        set.insert(buf);
                        fi.insert(buf);
                        pin[i] = buf;
                        f = true;
                        break;
                    }
                }
                if (f) {
                    break;
                }
            }
        }
        std::cout << ans << '\n';
        for (int i = 0; i < n; ++i) {
            std::cout << pin[i] << '\n';
        }
    }
    return 0;
}
