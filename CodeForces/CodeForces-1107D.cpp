#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    vector<vector<bool>> matrix(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        string hex; cin >> hex;
        for (int j = 0, x; j < hex.length(); ++j) {
            if (isdigit(hex[j])) x = hex[j] - '0';
            else x = hex[j] - 'A' + 10;
            for (int k = 3; k >= 0; --k) {
                int site = 4 - k - 1;
                matrix[i][j * 4 + k] = x & 1;
                x >>= 1;
            }
        }
    }
    vector<bool> r(n, false);
    for (int i = 1; i < n; ++i) {
        r[i] = true;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != matrix[i - 1][j]) r[i] = false;
        }
    }
    vector<bool> c(n, false);
    for (int j = 1; j < n; ++j) {
        c[j] = true;
        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] != matrix[i][j - 1]) c[j] = false;
        }
    }
    for (int x = n; x > 0; --x) {
        if (n % x) continue;
        int flag = true;
        for (int i = 0; i < n; ++i) {
            if ((i % x) && (!c[i] || !r[i])) flag = false;
        }
        if (flag) {
            cout << x << endl;
            break;
        }
    }
    return 0;
}

