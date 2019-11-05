#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int N, M, K;
multiset<pair<int, int> > S;
vector<pair<int, int> > Start[maxn];
vector<pair<int, int> > End[maxn];
long long Dp[maxn][205];

int main(int argc, char *argv[]) {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1, S, T, D, W; i <= K; ++i) {
        scanf("%d%d%d%d", &S, &T, &D, &W);
        Start[S].push_back(make_pair(-W, -D));
        End[T].push_back(make_pair(-W, -D));
    }
    for (int i = N; i >= 1; --i) {
        for (auto it : End[i]) S.insert(it);
        pair<int, int> Cur = make_pair(0, 0);
        if (!S.empty()) Cur = *S.begin();
        for (int j = 0; j <= M; ++j) {
            Dp[i][j] = Dp[Cur.first ? 1 - Cur.second : i + 1][j] - Cur.first;
            if (j) Dp[i][j] = min(Dp[i][j], Dp[i + 1][j - 1]);
        }
        for (auto it : Start[i]) S.erase(S.lower_bound(it));
    }
    printf("%lld\n", Dp[1][M]);
    return 0;
}

