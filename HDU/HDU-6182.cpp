#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    vector<unsigned long long> ans(16);
    for (unsigned long long i = 1; i <= 15; ++i) {
        ans[i] = 1;
        for (unsigned long long j = 1; j <= i; ++j) {
            ans[i] *= i;
        }
    }
    unsigned long long n;
    while (~scanf("%llu", &n)) {
        int Cnt = 0;
        for (unsigned long long i = 1; i <= 15; ++i) {
            if (ans[i] <= n) {
                Cnt++;
            }
            else {
                break;
            }
        }
        printf("%d\n", Cnt);
    }
    return 0;
}

