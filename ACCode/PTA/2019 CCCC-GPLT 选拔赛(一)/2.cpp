#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool Check(ll Key) {
    for (int i = 2; i * i <= Key; ++i) {
        if (Key % i == 0) return false;
    }
    return true;
}

ll N;

int main(int argc, char *argv[]) {
    scanf("%lld", &N);
    printf("%lld = ", N);
    for (ll i = 2; i <= N / 2; ++i) {
        if (Check(i) && Check(N - i)) {
            printf("%lld + %lld\n", i, N - i);
            break;
        }
    }
    return 0;
}

