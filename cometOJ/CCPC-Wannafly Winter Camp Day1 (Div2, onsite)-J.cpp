#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int N, M;
vector<long long> P[maxn];
int Max;
long long Ans;

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 1, A, C; i <= M; ++i) {
        scanf("%lld%d", &A, &C);
        P[C].push_back(A);
    }
    Max = -1;
    for (int i = 1; i <= N; ++i) {
        Max = max(Max, (int)P[i].size());
        sort(P[i].begin(), P[i].end());
    }
    Ans = 1e18;
    for (int k = Max + 1; k > 0; --k) {
        vector<long long> Residue;
        long long Res = 0; int Cnt = 0;
        for (int i = 1; i <= N; ++i) {
            int Size = P[i].size();
            for (int j = 0; j < Size; ++j) {
                if (Size >= k && j < Size - k + 1) {
                    Res += P[i][j];
                    Cnt++;
                }
                else Residue.push_back(P[i][j]);
            }
        }
        sort(Residue.begin(), Residue.end());
        if (Cnt < k) {
            for (int i = 0; i < k - Cnt; ++i) {
                Res += Residue[i];
            }
        }
        Ans = min(Ans, Res);
    }
    printf("%lld\n", Ans);
    return 0;
}

