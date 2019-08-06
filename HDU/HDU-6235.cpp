#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int t;
    scanf("%d", &t);
    for (int Case = 1, n; Case <= t; ++Case) {
        scanf("%d", &n);
        int book1 = 1, book2;
        if (n & 1) {
            book2 = (n + 1) / 2 + 1;
        }
        else {
            book2 = n / 2 + 1;
        }
        for (int i = 1; i <= n; ++i) {
            if (i & 1) {
                if (i == n) {
                    printf("%d ", (n + 1) / 2);
                    break;
                }
                printf("%d ", book1++);
            }
            else {
                printf("%d ", book2++);
            }
        }
        putchar('\n');
    }
    return 0;
}

