#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n, m; cin >> n >> m;
    vector<int> cnt(n, 0);
    int ans(0);
    for (int i = 0, x; i < m; ++i) {
        cin >> x; x--;
        if (cnt[x] == 0) {
            ans++;
            cnt[x]++;
        }
        else cnt[x]++;
        if (ans >= n) {
            cout << 1;
            ans = 0;
            for (int j = 0; j < n; ++j) {
                cnt[j]--;
                if (cnt[j]) ans++;
            }
        }
        else cout << 0;
    }
    cout << endl;
    return 0;
}

