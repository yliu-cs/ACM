#include <bits/stdc++.h>
using namespace std;

int Deg[5];
set<int> Flag;
int Cnt;

int main(int argc, char *argv[]) {
    for (int i = 1; i <= 4; ++i) Flag.insert(i);
    for (int i = 0, A, B; i < 3; ++i) {
        scanf("%d%d", &A, &B);
        Deg[A]++; Deg[B]++;
        Flag.erase(A); Flag.erase(B);
    }
    if (!Flag.empty()) {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= 4; ++i) {
        if (Deg[i] & 1) {
            Cnt++;
        }
    }
    if (Cnt != 2) printf("NO\n");
    else printf("YES\n");
    return 0;
}

