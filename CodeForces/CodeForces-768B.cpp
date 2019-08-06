#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int N;
int Number[maxn];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &Number[i]);
    }
    sort(Number, Number + N);
    for (int i = 0; i + 2 < N; ++i) {
        if (Number[i] + Number[i + 1] > Number[i + 2]) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

