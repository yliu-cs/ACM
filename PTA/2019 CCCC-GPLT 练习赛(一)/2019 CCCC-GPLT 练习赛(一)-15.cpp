#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    vector<int> matrix[5];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0, x; j < 5; ++j) {
            scanf("%d", &x);
            matrix[j].push_back(x);
        }
    }
    for (int i = 0; i < 5; ++i) sort(matrix[i].begin(), matrix[i].end());
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%4d", matrix[j][i]);
        }
        printf("\n");
    }
    return 0;
}

