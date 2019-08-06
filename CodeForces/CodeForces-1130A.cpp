#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;

int N;
int A[maxn];
int Cnt1, Cnt2;
int Std;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    Std = (int)ceil((double)N / 2.0);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        if (A[i] > 0) Cnt1++;
        else if (A[i] < 0) Cnt2++;
    }
    if (Cnt1 >= Std) printf("1\n");
    else if (Cnt2 >= Std) printf("-1\n");
    else printf("0\n");
    return 0;
}

