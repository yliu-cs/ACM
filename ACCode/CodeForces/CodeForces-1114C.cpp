#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll Cal(ll X, ll N) {
    ll Ans = 0;
    while(N) {
        Ans += N / X;
        N /= X;
    }
    return Ans;
}

int main() {
    ll Ans = 1e18 + 10;
    ll N, M;
    scanf("%lld %lld", &N, &M);
    for(ll i = 2; i * i <= M; i++) {
        if(M % i == 0) {
            ll Cnt = 0;
            while(M % i == 0) M /= i, Cnt++;
            Ans = min(Ans, Cal(i, N) / Cnt);
        }
    }
    if(M > 1) Ans = min(Ans, Cal(M, N));
    printf("%lld\n", Ans);
    return 0;
}
