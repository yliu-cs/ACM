#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int N;
char Str[maxn];
int Prefix[maxn];
int Suffix[maxn];
bool PreFlag[maxn], SufFlag[maxn];
int Ans;

int main(int argc, char *argv[]) {
    scanf("%d%s", &N, Str + 1);
    PreFlag[0] = true;
    for (int i = 1; i <= N; ++i) {
        Prefix[i] = Prefix[i - 1] + (Str[i] == '(' ? 1 : -1);
        PreFlag[i] = PreFlag[i - 1] & (Prefix[i] >= 0);
    }
    SufFlag[N + 1] = true;
    for (int i = N; i >= 1; --i) {
        Suffix[i] = Suffix[i + 1] + (Str[i] == ')' ? 1 : -1);
        SufFlag[i] = SufFlag[i + 1] & (Suffix[i] >= 0);
    }
    for (int i = 1; i <= N; ++i) {
        if (!PreFlag[i - 1] || !SufFlag[i + 1]) {
            continue;
        }
        if (Str[i] == '(') {
            if (Prefix[i - 1] > 0 && Prefix[i - 1] - Suffix[i + 1] == 1) {
                ++Ans;
            }
        }
        else {
            if (Suffix[i + 1] - Prefix[i - 1] == 1) {
                ++Ans;
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}

