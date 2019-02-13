#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    const int mod(1e9 + 7);
    int n, l, r; cin >> n >> l >> r;
    auto __mod = [&] (int key1, int key2) {
        int ans(key1 - key2);
        while (ans < 0) ans += 3;
        return ans % 3;
    };
    vector<long long> cnt(3, 0);
    cnt[0] = (r / 3) - ((l - 1) / 3);
    cnt[1] = ((r + 2) / 3) - ((l + 1) / 3);
    cnt[2] = ((r + 1) / 3) - (l / 3);
    vector<vector<long long>> dp(n, vector<long long>(3, 0));
    dp[0][0] = cnt[0]; dp[0][1] = cnt[1]; dp[0][2] = cnt[2];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][__mod(j, k)] * cnt[k] % mod) % mod;
            }
        }
    }
    cout << dp[n - 1][0] << endl;
    return 0;
}

