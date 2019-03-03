#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int x; cin >> x;
    int cnt = 0;
    for (int i = x / 5; i > 0; --i) {
        for (int j = (x - 5 * i) / 2; j > 0; --j) {
            for (int k = (x - 5 * i - 2 * j); k > 0; --k) {
                if (5 * i + 2 * j + k != x) continue;
                cnt++;
                cout << "fen5:" << i << ", fen2:" << j << ", fen1:" << k << ", total:" << i + j + k << endl;
            }
        }
    }
    cout << "count = " << cnt << endl;
    return 0;
}

