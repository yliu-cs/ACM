#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int Pre[maxn];
int Find(int Key) {return Pre[Key] == Key ? Key : Pre[Key] = Find(Pre[Key]);}
void Union(int Key1, int Key2) {Pre[Find(Key1)] = Find(Key2);}

int N;
int Tot;
vector<int> L[maxn];
map<int, int> M;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) Pre[i] = i;
    Tot = 1;
    for (int i = 1, U, V; i < N; ++i) {
        scanf("%d%d", &U, &V);
        int X = Find(U), Y = Find(V);
        if (!M[X] && !M[Y]) {
            L[Tot].push_back(U);
            L[Tot].push_back(V);
            M[X] = Tot++;
            Union(V, U);
        }
        else if (M[X] && M[Y]) {
            for (auto &it : L[M[Y]]) L[M[X]].push_back(it);
            Union(V, U);
        }
        else if (M[X]) {
            L[M[X]].push_back(V);
            Union(V, U);
        }
        else if (M[Y]) {
            L[M[Y]].push_back(U);
            Union(U, V);
        }
    }
    int F = Find(1);
    for (auto &it : L[M[F]]) cout << it << " ";
    return 0;
}

