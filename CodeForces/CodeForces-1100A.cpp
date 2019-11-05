#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n, k; cin >> n >> k;
    vector<int> array(n);
    for (auto &it : array) cin >> it;
    int ans(0);
    for (int b = 0; b < k; ++b) {
        int book(0);
        for (int i = 0; i < n; ++i) {
            if ((i + 1) % k == b) continue;
            if (array[i] == 1) book++;
            else book--;
        }
        ans = max(ans, abs(book));
    }
    cout << ans << endl;
    return 0;
}

