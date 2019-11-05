#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    long long N;
    scanf("%lld", &N);
    if (N & 1) {
        if (((N + 1) / 2) & 1) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
    else {
        if (N / 2 & 1) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
    return 0;
}
