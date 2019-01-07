#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int N, R;
    scanf("%d%d", &N, &R);
    vector<bool> Flag(N + 1, false);
    vector<int> Pos, Dp(N + 1, 0);
    for (int i = 1, X; i <= N; ++i) {
        scanf("%d", &X);
        if (X) {
            Pos.push_back(i);
        }
    }
    int Cur = -1, Size = int(Pos.size()), Index = 0;
    for (int i = 1; i <= N; ++i) {
        if (Flag[i]) {
            Dp[i] = Dp[i - 1];
        }
        else {
            int Temp = -1;
            for (int j = Cur + 1; j < Size; ++j) {
                if (Pos[j] - R + 1 > i) {
                    break;
                }
                else {
                    Temp = j;
                }
            }
            if (Temp != -1) {
                for (int j = Pos[Temp] - R + 1; j <= Pos[Temp] + R - 1; ++j) {
                    if (j > N) {
                        continue;
                    }
                    if (j < 1) {
                        continue;
                    }
                    Flag[j] = true;
                    if (j == Pos[Temp] - R + 1 || j == 1) {
                        Dp[j] = Dp[j - 1] + 1;
                    }
                    else {
                        Dp[j] = Dp[j - 1];
                    }
                }
                Cur = Temp;
            }
            else {
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n", Dp[N]);
    return 0;
}
