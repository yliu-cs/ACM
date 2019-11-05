#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int N;
int Ans;
int Array[maxn];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &Array[i]);
    }
    sort(Array + 1, Array + N + 1);
    Ans = min(Array[N - 1] - Array[1], Array[N] - Array[2]);
    printf("%d\n", Ans);
    return 0;
}

