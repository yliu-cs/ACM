#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int t;
    scanf("%d", &t);
    for (int Case = 1, p; Case <= t; ++Case) {
        scanf("%d", &p);
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < p; ++j) {
                printf("%d ", (i + j) % p);
            }
            printf("\n");
        }
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < p; ++j) {
                printf("%d ", (i * j) % p);
            }
            printf("\n");
        }
    }
    return 0;
}

