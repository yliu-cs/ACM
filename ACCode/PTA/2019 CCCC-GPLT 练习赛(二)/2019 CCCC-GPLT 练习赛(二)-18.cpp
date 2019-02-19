#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    vector<bool> vis(n, true);
    auto check = [&]() -> bool {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (vis[i])
                cnt++;
        return cnt == 1;
    };
    int cur = 0, cnt = 0;
    while (!check()) {
        if (vis[cur]) {
            cnt++;
            if (cnt == 3) {
                vis[cur] = false;
                cnt = 0;
            }
        }
        cur = (cur + 1) % n;
    }
    for (int i = 0; i < n; ++i)
        if (vis[i])
            cout << i + 1 << endl;
    return 0;
}

