#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K, A, B;
vector<ll> Pos;

ll Count(int Left, int Right) {
    return upper_bound(Pos.begin(), Pos.end(), Right) - lower_bound(Pos.begin(), Pos.end(), Left);
}

ll Dfs(ll Left, ll Right) {
    ll Cnt = Count(Left, Right);
    if (Cnt == 0) return A;
    ll Ans = B * Cnt * (Right - Left + 1);
    if (Left == Right) return Ans;
    ll Mid = (Left + Right) / 2;
    return min(Ans, Dfs(Left, Mid) + Dfs(Mid + 1, Right));
}

int main(int argc, char *argv[]) {
    scanf("%lld%lld%lld%lld", &N, &K, &A, &B);
    for (ll i = 1, X; i <= K; ++i) {
        scanf("%lld", &X);
        Pos.push_back(X);
    }
    sort(Pos.begin(), Pos.end());
    printf("%lld\n", Dfs(1, (1 << N)));
    return 0;
}
