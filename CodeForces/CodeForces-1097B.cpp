#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    function<bool(int, int)> Dfs = [&](int Index, int Sum) -> bool {
        if (Index == N) {
            if (Sum % 360 == 0) {
                return true;
            }
            return false;
        }
        if (Dfs(Index + 1, Sum + A[Index])) {
            return true;
        }
        if (Dfs(Index + 1, Sum - A[Index])) {
            return true;
        }
        return false;
    };
    if (Dfs(0, 0)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
