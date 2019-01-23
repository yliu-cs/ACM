#include <bits/stdc++.h>
using namespace std;

int X;
map<int, int> Cnt;

int main(int argc, char *argv[]) {
    Cnt.clear();
    while (~scanf("%d", &X)) {
        Cnt[X]++;
    }
    for (auto i : Cnt) {
        if (i.second == 1) {
            printf("%d\n", i.first);
            break;
        }
    }
    return 0;
}