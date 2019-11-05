#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

ll C[maxn][5];

void Init() {
    C[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        C[i][0] = 1;
        for (int j = 1; j < 5; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    Init();
    int t; cin >> t;
    for (int Case = 1; Case <= t; ++Case) {
        int n, m; cin >> n >> m;
        if (n < 3 || m < 3) {
            cout << "Case " << Case << ": " << 0 << endl;
            continue;
        }
        cout << "Case " << Case << ": " << ((C[n][3] + C[n][4]) % mod) * ((C[m][3] + C[m][4]) % mod) % mod << endl;
    }
    return 0;
}

