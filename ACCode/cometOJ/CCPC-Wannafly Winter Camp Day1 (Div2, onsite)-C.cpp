#include <bits/stdc++.h>
using namespace std;

int T;
long long A, B;
long long Prime[7] = {2, 3, 5, 7, 11, 13, 17};

void Solve() {
    if (__gcd(A, B) == 1) {
        printf("1\n%lld %lld\n", A, B);
        return;
    }
    printf("2\n");
    for (int i = 0; i < 7; ++i) {
        if (Prime[i] < A && Prime[i] < B) {
            if (A % Prime[i] && B % Prime[i]) {
                printf("%lld %lld\n", Prime[i], B - Prime[i]);
                printf("%lld %lld\n", A - Prime[i], Prime[i]);
                return;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%lld%lld", &A, &B);
        Solve();
    }
    return 0;
}
