#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int N, X;
    scanf("%d", &N);
    set<int> S;
    scanf("%d", &X);
    S.insert(X);
    int Ans = X;
    for (int i = 1; i < N; ++i) {
        scanf("%d", &X);
        set<int>::iterator NextIndex = S.lower_bound(X), PathIndex;
        if (NextIndex == S.end()) {
            Ans += X - *(--NextIndex);
            S.insert(X);
            continue;
        }
        else if (NextIndex == S.begin()) {
            Ans += *(NextIndex) - X;
            S.insert(X);
            continue;
        }
        else {
            PathIndex = --S.lower_bound(X);
        }
        Ans += min(X - *(PathIndex), *(NextIndex) - X);
        S.insert(X);
    }
    printf("%d\n", Ans);
    return 0;
}
