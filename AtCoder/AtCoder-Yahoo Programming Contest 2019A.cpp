#include <bits/stdc++.h>
using namespace std;

int N, K;

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &K);
    if (N >= 2 * K - 1) printf("YES\n");
    else printf("NO\n");
    return 0;
}

