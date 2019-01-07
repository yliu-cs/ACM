#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int N;
char Str[maxn];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    scanf("%s", Str);
    sort(Str, Str + N);
    printf("%s\n", Str);
    return 0;
}
