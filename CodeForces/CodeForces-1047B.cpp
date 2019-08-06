#include<bits/stdc++.h>
using namespace std;

int N;
int X, Y;
int Ans;

int main(int argc, char *argv[]) {
    Ans = -1;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &X, &Y);
        Ans = max(Ans, X + Y);
    }
    printf("%d\n", Ans);
    return 0;
}

