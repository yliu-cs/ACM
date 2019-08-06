#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    vector<vector<int>> matrix(3, vector<int>(3, 0));
    for (auto &i : matrix)
        for (auto &j : i)
            cin >> j;
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 3; ++i) {
            printf("%4d", matrix[i][j]);
        }
        cout << endl;
    }
    return 0;
}

