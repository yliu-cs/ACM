#include<bits/stdc++.h>
using namespace std;

int N, M;
int A[200010];
int B[200010];
map<int, int> Cnt;

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        scanf("%d%d", &A[i], &B[i]);
        Cnt[A[i]]++;
        Cnt[B[i]]++;
    }
    for (int i = 1; i <= M; ++i) {
        if (Cnt[A[i]] >= 2 && Cnt[B[i]] >= 2) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}

