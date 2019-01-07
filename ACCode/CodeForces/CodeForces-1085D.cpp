#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int N, S;
int Cnt[maxn];
int Ans;

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &S);
    memset(Cnt, 0, sizeof(Cnt));
    for (int i = 1, U, V; i < N; ++i) {
        scanf("%d%d", &U, &V);
        Cnt[U]++;
        Cnt[V]++;
    }
    for (int i = 1; i <= N; ++i) {
        if (Cnt[i] == 1) {
            Ans++;
        }
    }
    printf("%.18lf\n", (double)S / (double)(Ans) * 2.0);
    return 0;
}

