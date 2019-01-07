#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    map<int, int> mp[12];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        long long x = a[i];
        for (int j = 1; j <= 10; ++j) {
            x *= 10;
            x %= k;
            mp[j][x]++;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int len = log10(a[i]) + 1;
        ans += mp[len][(k - a[i] % k) % k];
        long long x = 1;
        for (int j = 1; j <= len; ++j) {
            x = x * 10 % k;
        }
        if (((x * a[i]) % k + a[i] % k) % k == 0) {
            ans--;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

