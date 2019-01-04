#include <bits/stdc++.h>
using namespace std;

const int maxn = 4;

int N;
int Cnt;
int A[maxn];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        Cnt = 0;
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &A[j]);
            if (A[j]) {
                Cnt++;
            }
        }
        if (!Cnt) {
            printf("Typically Otaku\n");
        }
        else if (Cnt == 1) {
            printf("Eye-opener\n");
        }
        else if (Cnt == 2) {
            printf("Young Traveller\n");
        }
        else if (Cnt == 3) {
            printf("Excellent Traveller\n");
        }
        else {
            printf("Contemporary Xu Xiake\n");
        }
    }
    return 0;
}

