#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll K, A, B;
ll Ans;

int main(int argc, char *argv[]) {
    scanf("%lld%lld%lld", &K, &A, &B);
    if (A >= B - 1 || K <= A - 1) {
        printf("%lld\n", K + 1);
        return 0;
    }
    Ans = 1;
    K -= A - 1; Ans += A - 1;
    Ans -= (K / 2) * A;
    Ans += (K / 2) * B;
    if (K & 1) Ans++;
    printf("%lld\n", Ans);
    return 0;
}

