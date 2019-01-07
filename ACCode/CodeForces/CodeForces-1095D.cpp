#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int N;
int Next[maxn][2];
vector<int> Ans;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &Next[i][0], &Next[i][1]);
    }
    Ans.push_back(1);
    int First = Next[1][0];
    if (Next[1][1] == Next[First][0] || Next[1][1] == Next[First][1]) {
        Ans.push_back(Next[1][0]);
    }
    else {
        Ans.push_back(Next[1][1]);
    }
    for (int i = 2; i < N; ++i) {
        int Size = (int)Ans.size();
        int Temp = Ans[Size - 2];
        if (Ans.back() == Next[Temp][0]) {
            Ans.push_back(Next[Temp][1]);
        }
        else {
            Ans.push_back(Next[Temp][0]);
        }
    }
    for (auto i : Ans) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}

