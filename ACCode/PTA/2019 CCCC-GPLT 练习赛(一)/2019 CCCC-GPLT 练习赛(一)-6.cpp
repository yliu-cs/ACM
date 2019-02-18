#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int N;
int W[maxn];
int Prefix[maxn];
int Ans;

int main(int argc, char *argv[]) {
    while (~scanf("%d", &N)) {
        Ans = -0x3f3f3f3f;
        memset(Prefix, 0, sizeof(Prefix));
        for (int i = 1; i <= N; ++i) scanf("%d", &W[i]);
        for (int i = 1; i <= N; ++i) Prefix[i] = max(Prefix[i - 1], W[i]);
        for (int i = 2; i <= N; ++i) Ans = max(Ans, Prefix[i - 1] - W[i]);
        printf("%d\n", Ans);
    }
    return 0;
}

