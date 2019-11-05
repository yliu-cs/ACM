#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    std::vector<int> l(n), r(n);
    std::multiset<int> L, R;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        L.insert(l[i]);
        R.insert(r[i]);
    }
    int ans = 0;
    // 遍历枚举
    for (int i = 0; i < n; ++i) {
        // 删除此段
        L.erase(L.find(l[i]));
        R.erase(R.find(r[i]));
        ans = std::max(ans, *R.begin() - *L.rbegin());
        L.insert(l[i]);
        R.insert(r[i]);
    }
    printf("%d\n", ans);
    return 0;
}

