#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int B, K;
int A[maxn];
bool Cur;

int main(int argc, char *argv[]) {
    scanf("%d%d", &B, &K);
    Cur = true;
    for (int i = 1; i <= K; ++i) {
        scanf("%d", &A[i]);
        if (i == K && Cur && (A[i] & 1)) {
            Cur = false;
            continue;
        }
        if ((A[i] & 1) && (B & 1)) Cur = !Cur;
    }
    if (Cur) printf("even\n");
    else printf("odd\n");
    return 0;
}

