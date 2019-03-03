#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int cur = 1, cnt = 0;
    while (cnt < n / 2) {
        for (int i = cnt; i < n - cnt; ++i) matrix[cnt][i] = cur++;
        for (int i = cnt + 1; i < n - cnt; ++i) matrix[i][n - cnt - 1] = cur++;
        for (int i = n - cnt - 2; i > cnt; --i) matrix[n - cnt - 1][i] = cur++;
        for (int i = n - cnt - 1; i > cnt; --i) matrix[i][cnt] = cur++;
        cnt++;
    }
    if (n & 1) matrix[n / 2][n / 2] = cur;
    for (auto &i : matrix) {
        for (auto &j : i) cout << setiosflags(ios::right) << setw(3) << j;
        cout << endl;
    }
    return 0;
}

