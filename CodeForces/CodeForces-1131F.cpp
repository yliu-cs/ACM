#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int Pre[maxn];
int Find(int Key) {return Pre[Key] == Key ? Key : Pre[Key] = Find(Pre[Key]);}
void Union(int Key1, int Key2) {Pre[Find(Key2)] = Find(Key1);}

int N;
list<int> L[maxn];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) Pre[i] = i;
    for (int i = 1; i <= N; ++i) L[i].push_back(i);
    for (int i = 1, U, V; i < N; ++i) {
        scanf("%d%d", &U, &V);
        L[Find(U)].splice(L[Find(U)].end(), L[Find(V)]);
        Union(U, V);
    }
    for (auto &it : L[Find(1)]) printf("%d ", it);
    printf("\n");
    return 0;
}

