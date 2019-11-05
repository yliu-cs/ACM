#include <bits/stdc++.h>
using namespace std;

int N;
int Cnt;
vector<int> Ans;

void Dfs(int Sum, int Pos, int Pre) {
    if (Sum == N) {
        printf("%d=%d", N, Ans[0]);
        for (int i = 1; i < Pos; ++i) printf("+%d", Ans[i]);
        if (Cnt == 3) {
            printf("\n");
            Cnt = 0;
        }
        else if (Pos == 1) {
            printf("\n");
            Cnt++;
        }
        else {
            printf(";");
            Cnt++;
        }
    }
    for (int i = Pre; i <= N; ++i) {
        if (Sum + i > N) continue;
        Ans[Pos] = i;
        Dfs(Sum + i, Pos + 1, i);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    Ans.assign(N, 1);
    Dfs(0, 0, 1);
    return 0;
}

