#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

char T[maxn << 1];
int Len[maxn << 1];

int Manacher(char Str[]) {
    int L = 0, StrLen = int(strlen(Str));
    T[L++] = '$'; T[L++] = '#';
    for (int i = 0; i < StrLen; ++i) {
        T[L++] = Str[i];
        T[L++] = '#';
    }
    int MX = 0, ID = 0, Ans = 0;
    for (int i = 0; i < L; ++i) {
        Len[i] = MX > i ? min(Len[2 * ID - i], MX - i) : 1;
        while (T[i + Len[i]] == T[i - Len[i]]) {
            Len[i]++;
        }
        if (i + Len[i] > MX) {
            MX = i + Len[i];
            ID = i;
        }
        Ans = max(Ans, Len[i] - 1);
    }
    return Ans;
}

char Str[maxn];

int main(int argc, char *argv[]) {
    while (scanf("%s", Str) != EOF) {
        printf("%d\n", Manacher(Str));
    }
    return 0;
}

