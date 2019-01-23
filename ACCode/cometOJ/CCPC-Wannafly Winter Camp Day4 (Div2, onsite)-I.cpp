#include<bits/stdc++.h>
using namespace std;

struct Monster {
    long long A, B;
};

int N;
Monster Card[1010];
long long Ans;
long long Res;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld%lld", &Card[i].A, &Card[i].B);
    }
    for (int k = 0; k <= N; ++k) {
        Res = 0;
        sort(Card + 1, Card + N + 1, [&](Monster Key1, Monster Key2) {
            return (Key1.A - Key1.B * k) > (Key2.A - Key2.B * k);
        });
        for (int i = 1; i <= k; ++i) {
            Res += Card[i].A;
        }
        for (int i = k + 1; i <= N; ++i) {
            Res += Card[i].B * k;
        }
        Ans = max(Ans, Res);
    }
    printf("%lld\n", Ans);
    return 0;
}

