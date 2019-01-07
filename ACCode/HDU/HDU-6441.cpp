#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, n, a; Case <= T; ++Case) {
        scanf("%d%d", &n, &a);
        if (n == 0 || n > 2) {
            printf("-1 -1\n");
        }
        else {
            if (n == 1) {
                printf("%d %d\n", a + 1, 2 * a + 1);
            }
            else {
                int cnt = 1;
                int temp = sqrt(a * 2 + 1);
                while (temp * temp != a * 2 + 1 && a % 2 == 0) {
                    cnt *= 2;
                    a /= 2;
                    temp = sqrt(a * 2 + 1);
                }
                if (a & 1) {
                    printf("%d %d\n", ((a * a - 1) / 2) * cnt, ((a * a - 1) / 2 + 1) * cnt);
                }
                else {
                    printf("%d %d\n", temp * cnt, ((temp * temp - 1) / 2 + 1) * cnt);
                }
            }
        }
    } 
    return 0;
}
