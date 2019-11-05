#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    long long n, k, ans;
    scanf("%lld%lld", &n, &k);
    if (k % n == 0) {
        ans = k / n;
    }
    else {
        ans = k / n + 1;
    }
    printf("%lld\n", ans);
    return 0;
}

