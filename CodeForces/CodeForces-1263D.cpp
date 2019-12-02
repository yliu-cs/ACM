#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    const int C = 26;
    std::vector<int> pre(C);
    for (int i = 0; i < C; ++i) {
        pre[i] = i;
    }
    std::function<int(int)> Find = [&](int x) {
        if (pre[x] == x) {
            return x;
        }
        pre[x] = Find(pre[x]);
        return pre[x];
    };
    auto Union = [&](int x, int y) {
        int xx = Find(x), yy = Find(y);
        if (xx != yy) {
            pre[xx] = yy;
        }
    };
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> s[i];
        int x = s[i][0] - 'a';
        for (int j = 1; j < (int)s[i].length(); ++j) {
            int y = s[i][j] - 'a';
            Union(x, y);
        }
    }
    std::set<int> set;
    for (int i = 0; i < n; ++i) {
        int x = s[i][0] - 'a';
        set.insert(Find(x));
    }
    std::cout << set.size() << '\n';
    return 0;
}