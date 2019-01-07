#include <bits/stdc++.h>
using namespace std;

vector<int> Ans;

void Solve(int N, int Factor) {
    if (N == 1) {
        Ans.push_back(Factor);
        return;
    }
    else if (N == 2) {
        Ans.push_back(Factor);
        Ans.push_back(Factor * 2);
        return;
    }
    else if (N == 3) {
        Ans.push_back(Factor);
        Ans.push_back(Factor);
        Ans.push_back(Factor * 3);
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if (i & 1) {
            Ans.push_back(Factor);
        }
    }
    Solve(N / 2, Factor * 2);
}

int main(int argc, char *argv[]) {
    int N;
    scanf("%d", &N);
    Solve(N, 1);
    for (auto i : Ans) {
        printf("%d ", i);
    }
    return 0;
}

