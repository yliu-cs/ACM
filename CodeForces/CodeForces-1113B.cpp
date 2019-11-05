#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    map<int, int> cnt;
    ll sum = 0, ans = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        sum += x;
        cnt[x]++;
    }
    for (int i = 1; i <= 100; ++i)
        for (int j = i; j <= 100; ++j)
            for (int k = 2; k <= 100; ++k)
                if (((j == i && cnt[i] > 1) || (j != i && cnt[i] && cnt[j])) && j % k == 0)
                    ans = max(ans, (ll)(j - j / k) - (i * k - i));
    ans = sum - ans;
    cout << ans << endl;
    return 0;
}

