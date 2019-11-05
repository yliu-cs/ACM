#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
    int N, M, K; scanf("%d%d%d", &N, &M, &K);
    vector<pair<ll, int> > A(N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i].first);
        A[i].second = i + 1;
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    ll Ans = 0;
    for (int i = 0; i < M * K; ++i) Ans += A[i].first;
    printf("%lld\n", Ans);
    sort(A.begin(), A.begin() + M * K, [&](pair<ll, int> Key1, pair<ll, int> Key2) {return Key1.second < Key2.second;});
    for (int i = M - 1, k = 0; k < K - 1; i += M, ++k) printf("%d ", A[i].second);
    return 0;
}

