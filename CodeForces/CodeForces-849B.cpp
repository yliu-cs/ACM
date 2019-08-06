#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
const double eps = 1e-8;

int N;
int Y[maxn];
bool Vis[maxn];
bool Ans;

bool Check(double K, int B) {
    memset(Vis, false, sizeof(Vis));
    int Cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (Y[i] - B == 1LL * K * (i - 1)) {
            Vis[i] = true;
            Cnt++;
        }
    }
    if (Cnt == N) return false;
    if (Cnt == N - 1) return true;
    int Low = 0;
    for (int i = 1; i <= N; ++i) {
        if (Low == 0 && !Vis[i]) {
            Low = i;
            break;
        }
    }
    for (int i = Low + 1; i <= N; ++i)
        if (!Vis[i])
            if (fabs((double)(Y[i] - Y[Low]) / (i - Low) - K) > eps)
                return false;
    return true;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%d", &Y[i]);
    Ans = false;
    Ans |= Check(1.0 * (Y[2] - Y[1]), Y[1]);
    Ans |= Check(0.5 * (Y[3] - Y[1]), Y[1]);
    Ans |= Check(1.0 * (Y[3] - Y[2]), Y[2] * 2 - Y[3]);
    if (Ans) printf("Yes\n");
    else printf("No\n");
    return 0;
}

