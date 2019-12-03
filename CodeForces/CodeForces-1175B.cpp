#include <bits/stdc++.h>

const long long MAX = (1ll << 32) - 1;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::cin.get();
    std::vector<std::string> str(n);
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, str[i]);
    }
    std::map<int, int> tp;
    std::stack<int> stk;
    for (int i = 0; i < n; ++i) {
        std::string opt = str[i].substr(0, 3);
        if (opt == "for") {
            stk.emplace(i);
        }
        else if (opt == "end") {
            tp[stk.top()] = i;
            stk.pop();
        }
    }
    bool f = true;
    std::function<long long(int, int)> Cal = [&](int s, int t) -> long long {
        long long ret = 0;
        int l = s;
        while (l <= t) {
            std::string opt = str[l].substr(0, 3);
            long long times = 0;
            for (int i = 4; i < (int)str[l].length(); ++i) {
                times = times * 10 + str[l][i] - '0';
            }
            if (opt == "for") {
                ret += Cal(l + 1, tp[l] - 1) * times;
                if (ret > MAX) {
                    f = false;
                }
                l = tp[l] + 1;
            }
            else if (opt == "add") {
                ++ret;
                if (ret > MAX) {
                    f = false;
                }
                ++l;
            }
        }
        return ret;
    };
    long long ans = Cal(0, n - 1);
    if (!f) {
        std::cout << "OVERFLOW!!!" << '\n';
    }
    else{
        std::cout << ans << '\n';
    }
    return 0;
}