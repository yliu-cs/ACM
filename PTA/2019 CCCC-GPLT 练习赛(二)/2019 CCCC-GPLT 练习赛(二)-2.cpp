#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    vector<vector<int>> matrix(4, vector<int>(4, 0));
    for (auto &i : matrix)
        for (auto &j : i)
            cin >> j;
    int ans = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j <= i; ++j)
            ans += matrix[i][j];
    cout << ans << endl;
    return 0;
}

