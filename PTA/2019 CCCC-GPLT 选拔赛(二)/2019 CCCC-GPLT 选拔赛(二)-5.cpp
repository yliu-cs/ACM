#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;

int Pre[maxn];
int Find(int Key) {return Pre[Key] == Key ? Key : Pre[Key] = Find(Pre[Key]);}
void Union(int Key1, int Key2) {Pre[Find(Key1)] = Find(Key2);}

struct Edge {int U, V, Cost;};
bool operator < (Edge Key1, Edge Key2) {return Key1.Cost < Key2.Cost;}
vector<Edge> G;

int N;
ll Ans;

void Kruskal() {
    sort(G.begin(), G.end());
    for (auto &it : G) {
        int X = Find(it.U), Y = Find(it.V);
        if (X == Y) continue;
        Ans += it.Cost;
        Union(X, Y);
    }
}


int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) Pre[i] = i;
    for (int i = 0, U, V, C, F; i < N * (N - 1) / 2; ++i) {
        scanf("%d%d%d%d", &U, &V, &C, &F);
        if (F == 1) Union(U, V);
        else G.push_back((Edge){U, V, C});
    }
    Kruskal();
    printf("%lld\n", Ans);
    return 0;
}

