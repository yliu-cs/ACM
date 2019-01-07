#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int N;
char Str[maxn];

int main(int argc, char *argv[]) {
    scanf("%d%s", &N, Str);
    for (int i = 1; i < N; ++i) {
        int Index = 0, Cur = i;
        while (Index < i) {
            if (Str[Cur] < Str[Index]) {
                printf("YES\n");
                return 0;
            }
            else if (Str[Cur] == Str[Index]) {
                Index++;
                Cur = (Cur + 1) % N;
            }
            else {
                break;
            }
        }
    }
    printf("NO\n");
    return 0;
}

