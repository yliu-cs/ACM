#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;

int N;
int K;
set<int> Link[maxn];
vector<int> Ans;
set<int> Vis;

void TopoSort() {
    queue<int> Que;
    for (int i = 1; i <= N; ++i) {
        if (Link[i].empty()) {
            Que.push(i);
            Vis.insert(i);
        }
    }
    while (!Que.empty()) {
        int Cur = Que.front(); Que.pop();
        Ans.push_back(Cur);
        for (int i = 1; i <= N; ++i) {
            if (Vis.find(i) != Vis.end()) continue;
            Link[i].erase(Cur);
            if (Link[i].empty()) {
                Que.push(i);
                Vis.insert(i);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &K);
        for (int j = 0, X; j < K; ++j) {
            scanf("%d", &X);
            Link[i].insert(X);
        }
    }
    TopoSort();
    if (Ans.size() == N) printf("1\n");
    else printf("0\n");
    return 0;
}

