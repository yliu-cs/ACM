#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                matrix[i][j] = 1;
                printf("%4d", matrix[i][j]);
                continue;
            }
            matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
            printf("%4d", matrix[i][j]);
        }
        cout << endl;
    }
    return 0;
}

