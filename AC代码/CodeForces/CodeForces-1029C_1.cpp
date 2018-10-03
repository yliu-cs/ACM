#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    std::vector<std::pair<int, int> > segs(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &segs[i].first, &segs[i].second);
    }
    sort(segs.begin(), segs.end(), [&] (const std::pair<int, int> &a, const std::pair<int, int> &b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });
    int l = 0, r = 1e9 + 5;
    for (int i = 1; i < n; ++i) {
        l = std::max(l, segs[i].first);
        r = std::min(r, segs[i].second);
    }
    int ans = std::max(0, r - l);
    sort(segs.begin(), segs.end(), [&] (const std::pair<int, int> &a, const std::pair<int, int> &b) {
        if (a.first != b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    });
    l = 0, r = 1e9 + 5;
    for (int i = 1; i < n; ++i) {
        l = std::max(l, segs[i].first);
        r = std::min(r, segs[i].second);
    }
    ans = std::max(ans, r - l);
    printf("%d\n", ans);
    return 0;
}

