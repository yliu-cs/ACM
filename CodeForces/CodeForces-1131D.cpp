#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;

int Pre[maxn];
int Find(int Key) {return Pre[Key] == Key ? Key : Pre[Key] = Find(Pre[Key]);}
void Union(int Key1, int Key2) {Pre[Find(Key1)] = Find(Key2);}

int N, M;
string G[maxn];
set<int> R[maxn];
int Deg[maxn];
set<int> Vis;
map<int, int> Ans;
bool Flag;
vector<int> Temp;

void TopoSort() {
    queue<int> Que;
    for (int i = 0; i < N + M; ++i) {
        if (Vis.find(Find(i)) != Vis.end()) continue;
        if (Deg[Find(i)] == 0) {
            Que.push(Find(i));
            Vis.insert(Find(i));
        }
    }
    int Cur = 1;
    while (!Que.empty()) {
        Temp.clear();
        while (!Que.empty()) {
            Temp.push_back(Que.front());
            Que.pop();
        }
        for (auto &i : Temp) {
            Ans[i] = Cur;
            for (auto &j : R[i]) {
                if (Vis.find(j) != Vis.end()) continue;
                Deg[j]--;
                if (Deg[j] == 0) {
                    Que.push(j);
                    Vis.insert(j);
                }
            }
        }
        Cur++;
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Flag = true;
    cin >> N >> M;
    for (int i = 0; i < N + M; ++i) Pre[i] = i;
    for (int i = 0; i < N; ++i) {
        cin >> G[i];
        for (int j = 0; j < M; ++j)
            if (G[i][j] == '=')
                if (Find(i) != Find(N + j))
                    Union(i, N + j);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (G[i][j] == '=') continue;
            int X = Find(i), Y = Find(N + j);
            if (X == Y) Flag = false;
            if (G[i][j] == '>') swap(X, Y);
            if (R[X].find(Y) == R[X].end()) {
                R[X].insert(Y);
                Deg[Y]++;
            }
        }
    }
    if (!Flag) {
        cout << "No" << endl;
        return 0;
    }
    TopoSort();
    for (int i = 0; i < N + M; ++i)
        if (Ans[Find(i)] == 0)
            Flag = false;
    if (Flag) {
        cout << "Yes" << endl;
        for (int i = 0; i < N; ++i) cout << Ans[Find(i)] << " ";
        cout << endl;
        for (int i = N; i < N + M; ++i) cout << Ans[Find(i)] << " ";
        cout << endl;
    }
    else cout << "No" << endl;
    return 0;
}

