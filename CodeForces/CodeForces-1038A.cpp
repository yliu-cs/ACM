#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, char *argv[]) {
    int N, K;
    scanf("%d%d", &N, &K);
    string str;
    cin >> str;
    map<int, int> Cnt;
    for (int i = 0; i < N; ++i) {
        Cnt[str[i] - 'A']++;
    }
    int Ans = INF;
    for (int i = 0; i < K; ++i) {
        Ans = min(Ans, Cnt[i]);
    }
    printf("%d\n", Ans * K);
    return 0;
}

