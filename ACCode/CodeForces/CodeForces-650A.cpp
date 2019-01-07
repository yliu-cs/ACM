#include<bits/stdc++.h>
using namespace std;

int N;
map<int, int> CntX, CntY;
map<pair<int, int>, int> Dif;
long long Ans;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0, X, Y; i < N; ++i) {
        scanf("%d%d", &X, &Y);
        Ans += CntX[X]++;
        Ans += CntY[Y]++;
        Ans -= Dif[make_pair(X, Y)]++;
    }
    printf("%lld\n", Ans);
    return 0;
}

