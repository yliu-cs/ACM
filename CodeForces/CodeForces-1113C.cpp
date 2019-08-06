#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = (1 << 20) + 5;

int N;
int Cur;
int Cnt[maxn][2];
ll Ans;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    Cnt[0][1] = 1;
    for (int i = 0, X; i < N; ++i) {
        scanf("%d", &X);
        Cur ^= X;
        Ans += Cnt[Cur][i & 1]++;
    }
    printf("%lld\n", Ans);
    return 0;
}

