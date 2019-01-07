#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int N;
long long Sum;
long long Length[maxn];
long long Ans;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    Sum = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", &Length[i]);
        Sum += Length[i];
    }
    sort(Length + 1, Length + N + 1);
    Ans = 2 * Length[N] - Sum + 1;
    printf("%lld\n", Ans);
    return 0;
}

