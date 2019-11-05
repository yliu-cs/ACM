#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main(int argc, char *argv[]) {
    vector<int> G[maxn];
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> Degree(N + 1, 0);
    for (int i = 1, U, V; i <= M; ++i) {
        scanf("%d%d", &U, &V);
        G[V].push_back(U);
        Degree[U]++;
    }
    priority_queue<int> Que;
    for (int i = 1; i <= N; ++i) {
        if (!Degree[i]) {
            Que.push(i);
        }
    }
    vector<int> List;
    while (!Que.empty()) {
        int Cur = Que.top(); Que.pop();
        List.push_back(Cur);
        for (auto i : G[Cur]) {
            Degree[i]--;
            if (!Degree[i]) {
                Que.push(i);
            }
        }
    }
    reverse(List.begin(), List.end());
    vector<int> Ans(N, 0);
    for (int i = 0; i < (int)List.size(); ++i) {
        Ans[List[i] - 1] = i + 1;
    }
    for (auto i : Ans) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}

