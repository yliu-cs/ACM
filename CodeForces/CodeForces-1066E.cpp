#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int N, M;
string A, B;
long long Ans;
int Cnt[maxn];
long long Pwd[maxn];

int main(int argc, char *argv[]) {
    cin >> N >> M;
    cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    Pwd[0] = 1;
    for (int i = 1; i <= N; ++i) {
        Pwd[i] = (Pwd[i - 1] * 2) % mod;
    }
    Cnt[M] = 0;
    for (int i = M - 1; i >= 0; --i) {
        Cnt[i] = (B[i] == '1') + Cnt[i + 1];
    }
    Ans = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == '1') {
            Ans += (Pwd[i] * Cnt[i]) % mod;
        }
        Ans %= mod;
    }
    printf("%lld\n", Ans);
    return 0;
}
