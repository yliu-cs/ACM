#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n, m; cin >> n >> m;
    int q; cin >> q;
    vector<int> cnt(2, 0);
    int ans = 0;
    while (q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (b == d && b == a + c) continue;
        if (b == a + c) {
            cnt[0]++;
            if (cnt[0] > n) {
                ans = 1;
                break;
            }
        }
        else if (d == a + c) {
            cnt[1]++;
            if (cnt[1] > m) {
                ans = 2;
                break;
            }
        }
    }
    if (ans == 1) cout << "A" << endl << cnt[1] << endl;
    else if (ans == 2) cout << "B" << endl << cnt[0] << endl;
    return 0;
}

