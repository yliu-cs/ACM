#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
const int maxn = 1e6 + 5;

ll N, K, M;
ll A[maxn];
ll Prefix[maxn];
db Ans;

int main(int argc, char *argv[]) {
    scanf("%lld%lld%lld", &N, &K, &M);
    for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
    sort(A + 1, A + N + 1);
    for (int i = 1; i <= N; ++i) Prefix[i] = Prefix[i - 1] + A[i];
    for (ll k = 0; k <= min(M, N - 1); ++k) {
       Ans = max(Ans, (db)(Prefix[N] - Prefix[k] + min(M - k, (N - k) * K)) / (db)(N - k));
    }
    printf("%.20Lf\n", Ans);
    return 0;
}

