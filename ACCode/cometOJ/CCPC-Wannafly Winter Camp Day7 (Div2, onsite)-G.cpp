#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = (int)(1e2 + 5);

int N, M;
vector<int> Pack[maxn];
set<int> Flag;
int Ans;

int Check(int Key) {
    set<int> Cnt; Cnt.clear();
    for (int i = 1; i <= M; ++i) {
        if (find(Pack[i].begin(), Pack[i].end(), Key) == Pack[i].end()) continue;
        for (auto it : Pack[i]) {
            if (it == Key) break;
            Cnt.insert(it);
        }
    }
    return (int)Cnt.size() + 1;
}

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) Flag.insert(i);
    for (int i = 1; i <= M; ++i) Pack[i].clear();
    for (int i = 1, K; i <= M; ++i) {
        scanf("%d", &K);
        for (int j = 1, X; j <= K; ++j) {
            scanf("%d", &X);
            Pack[i].push_back(X);
            if (Flag.find(X) != Flag.end()) Flag.erase(X);
        }
    }
    Ans = INF;
    for (int i = 1; i <= M; ++i) Ans = min(Ans, Check(Pack[i][0]));
    Ans = Flag.empty() ? Ans : 1;
    printf("%d\n", Ans);
    return 0;
}
