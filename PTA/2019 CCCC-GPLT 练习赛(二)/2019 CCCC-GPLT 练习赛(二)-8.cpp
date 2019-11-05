#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%1d*%1d=%-3d", i, j, i * j);
        }
        printf("\n");
    }
    return 0;
}

