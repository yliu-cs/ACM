#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int Len[6];
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &Len[i]);
    }
    int Length = Len[0] + Len[1] + Len[2];
    int Ans = Length * Length;
    Ans -= Len[0] * Len[0];
    Ans -= Len[2] * Len[2];
    Ans -= Len[4] * Len[4];
    printf("%d\n", Ans);
    return 0;
}

