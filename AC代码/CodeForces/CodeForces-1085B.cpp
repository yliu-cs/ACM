#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int N, K;
int Ans;

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &K);
    Ans = INF;
    for (int i = 1; i <= K; ++i) {
        if (N % i == 0) {
            int Temp = N / i;
            int X = Temp * K + i;
            if ((X / K) * (X % K) == N) {
                Ans = min(Ans, X);
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}

