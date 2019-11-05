#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

inline int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int main(int argc, char *argv[]) {
    int t;
    scanf("%d", &t);
    for (int Case = 1, n; Case <= t; ++Case) {
        scanf("%d", &n);
        vector<int> a(n);
        int ans = -INF;
        vector<int> pregcd(n, 1), subgcd(n, 1);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (i == 0) {
                pregcd[i] = a[i];
            }
            else {
                pregcd[i] = gcd(a[i], pregcd[i - 1]);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                subgcd[i] = a[i];
            }
            else {
                subgcd[i] = gcd(a[i], subgcd[i + 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            int temp;
            if (i == 0) {
                temp = subgcd[1];
            }
            else if (i == n - 1) {
                temp = pregcd[n - 2];
            }
            else {
                temp = gcd(pregcd[i - 1], subgcd[i + 1]);
            }
            ans = max(temp, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}

