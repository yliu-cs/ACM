#include <bits/stdc++.h>
const int maxn = 1e3 + 5;
const int inf = 1e9 + 5;
int n;
std::pair<int, int> pt[maxn];
std::set<std::pair<int, int>> set;
std::map<std::pair<int, int>, int> map;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1, x, y; i <= n; ++i) {
        std::cin >> pt[i].first >> pt[i].second;
        pt[i].first *= 2; pt[i].second *= 2;
        set.insert(pt[i]);
    }
    for (int i = 1, x, y; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            ++map[{(pt[i].first + pt[j].first) / 2, (pt[i].second + pt[j].second) / 2}];
        }
    }
    if (n <= 2) std::cout << 0 << '\n';
    else {
        int ans = inf;
        for (auto &v : map) ans = std::min(ans, (int)(n - 2 * v.second - set.count(v.first)));
        std::cout << ans << '\n';
    }
    return 0;
}