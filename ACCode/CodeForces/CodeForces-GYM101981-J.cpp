#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

bool IsPrime[maxn];
vector<int> PrimeFactor[maxn];

void Init() {
    memset(IsPrime, true, sizeof(IsPrime));
    for (long long i = 2; i < maxn; ++i) {
        if (IsPrime[i]) {
            PrimeFactor[i].push_back(i);
            for (long long j = i + i; j < maxn; j += i) {
                IsPrime[j] = false;
                PrimeFactor[j].push_back(i);
            }
        }
    }
    IsPrime[1] = false;
}

long long N;
int Cnt;
long long Ans;
bool Vis[maxn];
long long A[maxn], Factor[maxn];
vector<int> Pos[maxn];

int main(int argc, char *argv[]) {
    Init();
    scanf("%lld", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", &A[i]);
    }
    Ans = 0; Cnt = 1;
    memset(Vis, false, sizeof(Vis));
    for (int i = 1; i <= N; ++i) {
        for (int f : PrimeFactor[A[i]]) {
            if (!Vis[f]) {
                Vis[f] = true;
                Factor[Cnt++] = f;
            }
            Pos[f].push_back(i);
        }
    }
    for (int i = 1; i < Cnt; ++i) {
        long long Pre = 1;
        for (auto p : Pos[Factor[i]]) {
            Ans += (p - Pre + 1) * (N - p + 1);
            Pre = p + 1;
        }
    }
    printf("%lld\n", Ans);
    return 0;
}

