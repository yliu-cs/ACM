#include<bits/stdc++.h>
using namespace std;

int T;
int L, R;

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d%d", &L, &R);
        printf("%d %d\n", L, L * 2);
    }
    return 0;
}

